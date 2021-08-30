/*************************************************************************/
/*  rid_owner.h                                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef RID_OWNER_H
#define RID_OWNER_H

#include <godot_cpp/godot.hpp>
#include <godot_cpp/core/memory.hpp>
#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include <stdio.h>
#include <typeinfo>

// ========================================= //
// FIXME: Move to godot-cpp                  //
// ========================================= //

#define memalloc(m_size) Memory::alloc_static(m_size)
#define memrealloc(m_mem, m_size) Memory::realloc_static(m_mem, m_size)
#define memfree(m_mem) Memory::free_static(m_mem)

// ========================================= //
// FIXME: Move to godot-cpp                  //
// ========================================= //

using namespace godot;

template <class T>
class RID_Alloc {
	T **chunks = nullptr;
	uint32_t **free_list_chunks = nullptr;
	uint32_t **validator_chunks = nullptr;

	uint32_t elements_in_chunk;
	uint32_t max_alloc = 0;
	uint32_t alloc_count = 0;

	const char *description = nullptr;

	_FORCE_INLINE_ RID _allocate_rid() {
		return godot::UtilityFunctions::rid_from_int64(godot::UtilityFunctions::rid_allocate_id());
	}

public:
	RID make_rid() {
		RID rid = _allocate_rid();
		initialize_rid(rid);
		return rid;
	}
	RID make_rid(const T &p_value) {
		RID rid = _allocate_rid();
		initialize_rid(rid, p_value);
		return rid;
	}

	//allocate but don't initialize, use initialize_rid afterwards
	RID allocate_rid() {
		return _allocate_rid();
	}

	_FORCE_INLINE_ T *getornull(const RID &p_rid, bool p_initialize = false) {
		if (p_rid == RID()) {
			return nullptr;
		}

		uint64_t id = p_rid.get_id();
		uint32_t idx = uint32_t(id & 0xFFFFFFFF);
		if (unlikely(idx >= max_alloc)) {
			return nullptr;
		}

		uint32_t idx_chunk = idx / elements_in_chunk;
		uint32_t idx_element = idx % elements_in_chunk;

		uint32_t validator = uint32_t(id >> 32);

		if (unlikely(p_initialize)) {
			if (unlikely(!(validator_chunks[idx_chunk][idx_element] & 0x80000000))) {
				ERR_FAIL_V_MSG(nullptr, "Initializing already initialized RID");
			}

			if (unlikely((validator_chunks[idx_chunk][idx_element] & 0x7FFFFFFF) != validator)) {
				ERR_FAIL_V_MSG(nullptr, "Attempting to initialize the wrong RID");
				return nullptr;
			}

			validator_chunks[idx_chunk][idx_element] &= 0x7FFFFFFF; //initialized

		} else if (unlikely(validator_chunks[idx_chunk][idx_element] != validator)) {
			if ((validator_chunks[idx_chunk][idx_element] & 0x80000000) && validator_chunks[idx_chunk][idx_element] != 0xFFFFFFFF) {
				ERR_FAIL_V_MSG(nullptr, "Attempting to use an uninitialized RID");
			}
			return nullptr;
		}

		T *ptr = &chunks[idx_chunk][idx_element];

		return ptr;
	}
	void initialize_rid(RID p_rid) {
		T *mem = getornull(p_rid, true);
		ERR_FAIL_COND(!mem);
		memnew_placement(mem, T);
	}
	void initialize_rid(RID p_rid, const T &p_value) {
		T *mem = getornull(p_rid, true);
		ERR_FAIL_COND(!mem);
		memnew_placement(mem, T(p_value));
	}

	_FORCE_INLINE_ bool owns(const RID &p_rid) {
		uint64_t id = p_rid.get_id();
		uint32_t idx = uint32_t(id & 0xFFFFFFFF);
		if (unlikely(idx >= max_alloc)) {
			return false;
		}

		uint32_t idx_chunk = idx / elements_in_chunk;
		uint32_t idx_element = idx % elements_in_chunk;

		uint32_t validator = uint32_t(id >> 32);

		bool owned = (validator_chunks[idx_chunk][idx_element] & 0x7FFFFFFF) == validator;

		return owned;
	}

	_FORCE_INLINE_ void free(const RID &p_rid) {
		uint64_t id = p_rid.get_id();
		uint32_t idx = uint32_t(id & 0xFFFFFFFF);
		if (unlikely(idx >= max_alloc)) {
			ERR_FAIL();
		}

		uint32_t idx_chunk = idx / elements_in_chunk;
		uint32_t idx_element = idx % elements_in_chunk;

		uint32_t validator = uint32_t(id >> 32);
		if (unlikely(validator_chunks[idx_chunk][idx_element] & 0x80000000)) {
			ERR_FAIL_MSG("Attempted to free an uninitialized or invalid RID");
		} else if (unlikely(validator_chunks[idx_chunk][idx_element] != validator)) {
			ERR_FAIL();
		}

		chunks[idx_chunk][idx_element].~T();
		validator_chunks[idx_chunk][idx_element] = 0xFFFFFFFF; // go invalid

		alloc_count--;
		free_list_chunks[alloc_count / elements_in_chunk][alloc_count % elements_in_chunk] = idx;
	}

	_FORCE_INLINE_ uint32_t get_rid_count() const {
		return alloc_count;
	}

	_FORCE_INLINE_ T *get_ptr_by_index(uint32_t p_index) {
		ERR_FAIL_UNSIGNED_INDEX_V(p_index, alloc_count, nullptr);
		uint64_t idx = free_list_chunks[p_index / elements_in_chunk][p_index % elements_in_chunk];
		T *ptr = &chunks[idx / elements_in_chunk][idx % elements_in_chunk];
		return ptr;
	}

	_FORCE_INLINE_ RID get_rid_by_index(uint32_t p_index) {
		ERR_FAIL_INDEX_V(p_index, alloc_count, RID());
		uint64_t idx = free_list_chunks[p_index / elements_in_chunk][p_index % elements_in_chunk];
		uint64_t validator = validator_chunks[idx / elements_in_chunk][idx % elements_in_chunk];

		RID rid = godot::UtilityFunctions::rid_from_int64((validator << 32) | idx);
		return rid;
	}

	void set_description(const char *p_descrption) {
		description = p_descrption;
	}

	RID_Alloc(uint32_t p_target_chunk_byte_size = 65536) {
		elements_in_chunk = sizeof(T) > p_target_chunk_byte_size ? 1 : (p_target_chunk_byte_size / sizeof(T));
	}

	~RID_Alloc() {
		if (alloc_count) {
			if (description) {
				//ERR_PRINT("ERROR: " + String::num(alloc_count) + " RID allocations of type '" + description + "' were leaked at exit.");
			} else {
#ifdef NO_SAFE_CAST
				//ERR_PRINT("ERROR: " + String::num(alloc_count) + " RID allocations of type 'unknown' were leaked at exit.");
#else
				//ERR_PRINT("ERROR: " + String::num(alloc_count) + " RID allocations of type '" + typeid(T).name() + "' were leaked at exit.");
#endif
			}

			for (size_t i = 0; i < max_alloc; i++) {
				uint64_t validator = validator_chunks[i / elements_in_chunk][i % elements_in_chunk];
				if (validator & 0x80000000) {
					continue; //uninitialized
				}
				if (validator != 0xFFFFFFFF) {
					chunks[i / elements_in_chunk][i % elements_in_chunk].~T();
				}
			}
		}

		uint32_t chunk_count = max_alloc / elements_in_chunk;
		for (uint32_t i = 0; i < chunk_count; i++) {
			memfree(chunks[i]);
			memfree(validator_chunks[i]);
			memfree(free_list_chunks[i]);
		}

		if (chunks) {
			memfree(chunks);
			memfree(free_list_chunks);
			memfree(validator_chunks);
		}
	}
};

template <class T>
class RID_PtrOwner {
	RID_Alloc<T *> alloc;

public:
	_FORCE_INLINE_ RID make_rid(T *p_ptr) {
		return alloc.make_rid(p_ptr);
	}

	_FORCE_INLINE_ RID allocate_rid() {
		return alloc.allocate_rid();
	}

	_FORCE_INLINE_ void initialize_rid(RID p_rid, T *p_ptr) {
		alloc.initialize_rid(p_rid, p_ptr);
	}

	_FORCE_INLINE_ T *getornull(const RID &p_rid) {
		T **ptr = alloc.getornull(p_rid);
		if (unlikely(!ptr)) {
			return nullptr;
		}
		return *ptr;
	}

	_FORCE_INLINE_ void replace(const RID &p_rid, T *p_new_ptr) {
		T **ptr = alloc.getornull(p_rid);
		ERR_FAIL_COND(!ptr);
		*ptr = p_new_ptr;
	}

	_FORCE_INLINE_ bool owns(const RID &p_rid) {
		return alloc.owns(p_rid);
	}

	_FORCE_INLINE_ void free(const RID &p_rid) {
		alloc.free(p_rid);
	}

	_FORCE_INLINE_ uint32_t get_rid_count() const {
		return alloc.get_rid_count();
	}

	_FORCE_INLINE_ RID get_rid_by_index(uint32_t p_index) {
		return alloc.get_rid_by_index(p_index);
	}

	_FORCE_INLINE_ T *get_ptr_by_index(uint32_t p_index) {
		return *alloc.get_ptr_by_index(p_index);
	}

	void set_description(const char *p_descrption) {
		alloc.set_description(p_descrption);
	}

	RID_PtrOwner(uint32_t p_target_chunk_byte_size = 65536) :
			alloc(p_target_chunk_byte_size) {}
};

template <class T>
class RID_Owner {
	RID_Alloc<T> alloc;

public:
	_FORCE_INLINE_ RID make_rid() {
		return alloc.make_rid();
	}
	_FORCE_INLINE_ RID make_rid(const T &p_ptr) {
		return alloc.make_rid(p_ptr);
	}

	_FORCE_INLINE_ RID allocate_rid() {
		return alloc.allocate_rid();
	}

	_FORCE_INLINE_ void initialize_rid(RID p_rid) {
		alloc.initialize_rid(p_rid);
	}

	_FORCE_INLINE_ void initialize_rid(RID p_rid, const T &p_ptr) {
		alloc.initialize_rid(p_rid, p_ptr);
	}

	_FORCE_INLINE_ T *getornull(const RID &p_rid) {
		return alloc.getornull(p_rid);
	}

	_FORCE_INLINE_ bool owns(const RID &p_rid) {
		return alloc.owns(p_rid);
	}

	_FORCE_INLINE_ void free(const RID &p_rid) {
		alloc.free(p_rid);
	}

	_FORCE_INLINE_ uint32_t get_rid_count() const {
		return alloc.get_rid_count();
	}

	_FORCE_INLINE_ RID get_rid_by_index(uint32_t p_index) {
		return alloc.get_rid_by_index(p_index);
	}

	_FORCE_INLINE_ T *get_ptr_by_index(uint32_t p_index) {
		return alloc.get_ptr_by_index(p_index);
	}

	void set_description(const char *p_descrption) {
		alloc.set_description(p_descrption);
	}
	RID_Owner(uint32_t p_target_chunk_byte_size = 65536) :
			alloc(p_target_chunk_byte_size) {}
};

#endif // RID_OWNER_H
