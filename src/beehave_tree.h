#ifndef BEEHAVETREE_H
#define BEEHAVETREE_H

#include <godot_cpp/classes/node.hpp>

namespace godot {

class BeehaveTree : public Node {
    GDCLASS(BeehaveTree, Node)

public:
    BeehaveTree();
    ~BeehaveTree();

    void set_tree_enabled(bool p_enabled);
    bool get_tree_enabled() const {return tree_enabled;}   

private:
    bool tree_enabled;

protected:
    static void _bind_methods();
};

}

#endif
