#include "beehave_node.h"
#include "beehave_tree.h"
#include "godot_cpp/core/method_ptrcall.hpp"
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
    call("_tick", actor, blackboard);
    return TreeStatus::SUCCESS;
}

void BeehaveNode::after_run(Node *actor, Blackboard *blackboard) {
    call("_before_run", actor, blackboard);
}

void BeehaveNode::_before_run(Node *actor, Blackboard *blackboard) {
    
}

int BeehaveNode::_tick(Node *actor, Blackboard *blackboard) {
    return TreeStatus::SUCCESS;
}

void BeehaveNode::_after_run(Node *actor, Blackboard *blackboard) {

}

void BeehaveNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("before_run"), &BeehaveNode::before_run);
    ClassDB::bind_method(D_METHOD("tick"), &BeehaveNode::tick);
    ClassDB::bind_method(D_METHOD("after_run"), &BeehaveNode::after_run);

    BIND_VIRTUAL_METHOD(BeehaveNode, _before_run);
    BIND_VIRTUAL_METHOD(BeehaveNode, _tick);
    BIND_VIRTUAL_METHOD(BeehaveNode, _after_run);
}