#include "beehave_tree.h"
#include "godot_cpp/classes/global_constants.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

enum TreeStatus {
    SUCCESS,
    FAILURE,
    RUNNING
};

BeehaveTree::BeehaveTree() {
    // Initialize any variables here.
    tree_enabled = false;
}

void BeehaveTree::set_tree_enabled(bool p_enabled) {
    tree_enabled = p_enabled;
    set_physics_process(tree_enabled);
    if (tree_enabled) {
        
    } else {

    }
}

BeehaveTree::~BeehaveTree() {
    // Add your cleanup here.
}

void BeehaveTree::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_tree_enabled", "enabled"), &BeehaveTree::set_tree_enabled);
	ClassDB::bind_method(D_METHOD("get_tree_enabled"), &BeehaveTree::get_tree_enabled);

    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "enabled", PROPERTY_HINT_NONE), "set_tree_enabled", "get_tree_enabled");
}