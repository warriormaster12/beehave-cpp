#include "beehave_node.h"
#include "beehave_tree.h"
#include "godot_cpp/core/method_ptrcall.hpp"
#include "godot_cpp/variant/string.hpp"
#include "godot_cpp/variant/string_name.hpp"
#include "godot_cpp/variant/typed_array.hpp"
#include "utils.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

BeehaveNode::BeehaveNode() {

}

BeehaveNode::~BeehaveNode() {

}

void BeehaveNode::before_run(Node *actor, Blackboard *blackboard) {
    call("_before_run", actor, blackboard);
}

int BeehaveNode::tick(Node *actor, Blackboard *blackboard) {
    return call("_tick", actor, blackboard);
}

void BeehaveNode::after_run(Node *actor, Blackboard *blackboard) {
    call("_before_run", actor, blackboard);
}

TypedArray<StringName> BeehaveNode::get_class_name() {
    return call("_get_class_name");
}

void BeehaveNode::_before_run(Node *actor, Blackboard *blackboard) {
    
}

int BeehaveNode::_tick(Node *actor, Blackboard *blackboard) {
    return BeehaveTreeStatus::SUCCESS;
}

void BeehaveNode::_after_run(Node *actor, Blackboard *blackboard) {

}

TypedArray<StringName> BeehaveNode::_get_class_name() {
    class_names.push_back("BeehaveNode");
    return class_names;
}

void BeehaveNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("before_run", "actor", "blackboard"), &BeehaveNode::before_run);
    ClassDB::bind_method(D_METHOD("tick", "actor", "blackboard"), &BeehaveNode::tick);
    ClassDB::bind_method(D_METHOD("after_run", "actor", "blackboard"), &BeehaveNode::after_run);
    ClassDB::bind_method(D_METHOD("get_class_name"), &BeehaveNode::get_class_name);

    BIND_VIRTUAL_METHOD(BeehaveNode, _before_run);
    BIND_VIRTUAL_METHOD(BeehaveNode, _tick);
    BIND_VIRTUAL_METHOD(BeehaveNode, _after_run);
    BIND_VIRTUAL_METHOD(BeehaveNode, _get_class_name);

    BIND_ENUM_CONSTANT(SUCCESS);
    BIND_ENUM_CONSTANT(FAILURE);
    BIND_ENUM_CONSTANT(RUNNING);
}