#ifndef BEEHAVENODE_H
#define BEEHAVENODE_H

#include "blackboard.h"
#include "godot_cpp/variant/node_path.hpp"
#include <godot_cpp/classes/node.hpp>

namespace godot {
    class BeehaveNode : public Node {
        GDCLASS(BeehaveNode, Node)

    public:
        BeehaveNode();
        ~BeehaveNode();
        //workaround https://github.com/godotengine/godot-cpp/issues/1199
        void before_run(Node *actor, Blackboard *blackboard);
        int tick(Node *actor, Blackboard *blackboard);
        void after_run(Node *actor, Blackboard *blackboard);
        virtual void _before_run(Node *actor, Blackboard *blackboard);
        virtual int _tick(Node *actor, Blackboard *blackboard);
        virtual void _after_run(Node *actor, Blackboard *blackboard);
    private:

    protected:
        static void _bind_methods();
    };
}

#endif
