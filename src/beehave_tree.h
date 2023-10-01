#ifndef BEEHAVETREE_H
#define BEEHAVETREE_H

#include "blackboard.h"
#include "godot_cpp/variant/node_path.hpp"
#include <godot_cpp/classes/node.hpp>

namespace godot {

    

    class BeehaveTree : public Node {
        GDCLASS(BeehaveTree, Node)

    public:
        BeehaveTree();
        ~BeehaveTree();

        void set_tree_enabled(bool p_enabled);
        bool get_tree_enabled() const {return tree_enabled;}
        void set_actor(NodePath p_actor_path);
        Node *get_actor() const {return actor;}
        void set_blackboard(NodePath p_blackboard_path);
        Blackboard *get_blackboard() const {return blackboard;}

        virtual void _ready() override;
        virtual void _physics_process(double delta) override;

    private:
        bool tree_enabled;
        Node *actor;
        Blackboard *blackboard;
        int status;

        int tick();

    protected:
        static void _bind_methods();
    };

}

#endif
