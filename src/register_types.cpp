#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/memory.hpp>

#include "ts_test.h"

using namespace godot;

extern "C" {

void register_types() {
	ClassDB::register_class<TextServerTest>();

	TextServerManager *ts_man = TextServerManager::get_singleton();
	if (ts_man) {
		Ref<TextServerTest> ts;
		ts.instantiate();
		ts_man->add_interface(ts);
	}
}

void unregister_types() {
	printf ("unreg\n");
}

GDNativeBool GDN_EXPORT ts_test_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization) {
	printf("Init library...\n");
	GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

	init_obj.register_server_initializer(register_types);
	init_obj.register_server_terminator(unregister_types);

	return init_obj.init();
}

} /* extern "C" */
