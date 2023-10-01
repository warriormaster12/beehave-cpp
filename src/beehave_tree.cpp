#include "beehave_tree.h"
#include "beehave_node.h"
#include "blackboard.h"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/error_macros.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/variant/node_path.hpp"
#include <godot_cpp/core/class_db.hpp>
#include "utils.h"

using namespace godot;

BeehaveTree::BeehaveTree() {
    // Initialize any variables here.
    tree_enabled = false;
    status = -1;
}

void BeehaveTree::set_tree_enabled(bool p_enabled) {
    tree_enabled = p_enabled;
    set_physics_process_internal(tree_enabled);
    if (tree_enabled) {
        emit_signal("on_tree_enabled");
    } else {
        emit_signal("on_tree_disabled");
    }
}

void BeehaveTree::set_actor(const NodePath &p_actor_path) {
    actor = p_actor_path;
}

void BeehaveTree::set_blackboard(const NodePath &p_blackboard_path) {
    blackboard = p_blackboard_path;
}

int BeehaveTree::tick() {
    BeehaveNode *child = cast_to<BeehaveNode>(get_child(0));
    if (child == nullptr) {
        return status;
    }
    if (status != BeehaveTreeStatus::RUNNING) {
        child->before_run(get_node_or_null(actor), cast_to<Blackboard>(get_node_or_null(blackboard)));
    }

    child->tick(get_node_or_null(actor), cast_to<Blackboard>(get_node_or_null(blackboard)));

    if (status != BeehaveTreeStatus::RUNNING) {
        child->after_run(get_node_or_null(actor), cast_to<Blackboard>(get_node_or_null(blackboard)));
    }
    return status;
}

void BeehaveTree::_notification(int p_what) {
    switch (p_what) {
        case NOTIFICATION_READY: {
			if (Engine::get_singleton()->is_editor_hint()) {
                set_physics_process(false);
                set_process(false);
                return;
            } else {
                set_physics_process(tree_enabled);
            }
		} break;
        case NOTIFICATION_PHYSICS_PROCESS: {
            if (this->get_child_count() == 1) {
                tick();
            }
        } break;
    
    }
}

BeehaveTree::~BeehaveTree() {
    // Add your cleanup here.
}

void BeehaveTree::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_tree_enabled", "enabled"), &BeehaveTree::set_tree_enabled);
	ClassDB::bind_method(D_METHOD("get_tree_enabled"), &BeehaveTree::get_tree_enabled);
    ClassDB::bind_method(D_METHOD("set_actor", "actor_path"), &BeehaveTree::set_actor);
	ClassDB::bind_method(D_METHOD("get_actor"), &BeehaveTree::get_actor);
    ClassDB::bind_method(D_METHOD("set_blackboard", "blackboard_path"), &BeehaveTree::set_blackboard);
	ClassDB::bind_method(D_METHOD("get_blackboard"), &BeehaveTree::get_blackboard);

    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "enabled", PROPERTY_HINT_NONE), "set_tree_enabled", "get_tree_enabled");
    ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "actor", PROPERTY_HINT_NODE_PATH_VALID_TYPES, "Node"), "set_actor", "get_actor");
    ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "blackboard", PROPERTY_HINT_NODE_PATH_VALID_TYPES, "Blackboard"), "set_blackboard", "get_blackboard");


    ADD_SIGNAL(MethodInfo("on_tree_enabled"));
    ADD_SIGNAL(MethodInfo("on_tree_disabled"));
}