#ifndef BEEHAVETREE_H
#define BEEHAVETREE_H

#include "blackboard.h"
#include "godot_cpp/core/binder_common.hpp"
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
        void set_actor(const NodePath &p_actor_path);
        NodePath get_actor() const {return actor;}
        void set_blackboard(const NodePath &p_blackboard_path);
        NodePath get_blackboard() const {return blackboard;}

        void _notification(int p_what);

    private:
        bool tree_enabled;
        NodePath actor;
        NodePath blackboard;
        int status;

        int tick();

    protected:
        static void _bind_methods();
    };
}

#endif
