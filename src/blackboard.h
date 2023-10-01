#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include "godot_cpp/variant/dictionary.hpp"
#include "godot_cpp/variant/node_path.hpp"
#include "godot_cpp/variant/variant.hpp"
#include <godot_cpp/classes/node.hpp>

namespace godot {

    class Blackboard : public Node {
        GDCLASS(Blackboard, Node)

    public:
        Blackboard();
        ~Blackboard();
        void set_data(Dictionary p_data);
        Dictionary get_data() const {return data;}

        void set_value(Variant p_key, Variant p_value);
        Variant get_value(Variant p_key, Variant default_value = 0);
        bool has_value(Variant p_key);
        void erase_entry(Variant p_key);
    private:
        Dictionary data;
    protected:
        static void _bind_methods();
    };

}

#endif