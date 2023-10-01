#include "beehave_tree.h"
#include "beehave_node.h"
#include "blackboard.h"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/global_constants.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/variant/node_path.hpp"
#include <godot_cpp/core/class_db.hpp>
#include "utils.h"

using namespace godot;

BeehaveTree::BeehaveTree() {
    // Initialize any variables here.
    tree_enabled = false;
    actor = nullptr;
    blackboard = nullptr;
    status = -1;
}

void BeehaveTree::set_tree_enabled(bool p_enabled) {
    tree_enabled = p_enabled;
    set_physics_process(tree_enabled);
    if (tree_enabled) {
        emit_signal("on_tree_enabled");
    } else {
        emit_signal("on_tree_disabled");
    }
}

void BeehaveTree::set_actor(NodePath p_actor_path) {
    actor = get_node<Node>(p_actor_path);
}

void BeehaveTree::set_blackboard(NodePath p_blackboard_path) {
    blackboard = get_node<Blackboard>(p_blackboard_path);
}

int BeehaveTree::tick() {
    BeehaveNode *child = cast_to<BeehaveNode>(get_child(0));
    if (child == nullptr) {
        return status;
    }
    if (status != TreeStatus::RUNNING) {
        child->before_run(actor, blackboard);
    }

    child->tick(actor, blackboard);

    if (status != TreeStatus::RUNNING) {
        child->after_run(actor, blackboard);
    }
    return status;
}

void BeehaveTree::_ready() {
    if (Engine::get_singleton()->is_editor_hint()) {
        set_physics_process(false);
        set_process(false);
        return;
    }
}

void BeehaveTree::_physics_process(double delta) {
    if (this->get_child_count() == 1) {
        tick();
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
    ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "actor", PROPERTY_HINT_NONE), "set_actor", "get_actor");
    ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "blackboard", PROPERTY_HINT_NONE), "set_blackboard", "get_blackboard");


    ADD_SIGNAL(MethodInfo("on_tree_enabled"));
    ADD_SIGNAL(MethodInfo("on_tree_disabled"));
}