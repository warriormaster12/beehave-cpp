#ifndef BEEHAVENODE_H
#define BEEHAVENODE_H

#include "blackboard.h"
#include "godot_cpp/core/binder_common.hpp"
#include "utils.h"
#include "godot_cpp/variant/node_path.hpp"
#include "godot_cpp/variant/string_name.hpp"
#include "godot_cpp/variant/typed_array.hpp"
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
        TypedArray<StringName> get_class_name();
        virtual void _before_run(Node *actor, Blackboard *blackboard);
        virtual int _tick(Node *actor, Blackboard *blackboard);
        virtual void _after_run(Node *actor, Blackboard *blackboard);
        virtual TypedArray<StringName> _get_class_name();
    private:
        TypedArray<StringName> class_names;
    protected:
        static void _bind_methods();
    };
}

VARIANT_ENUM_CAST(BeehaveTreeStatus);

#endif
