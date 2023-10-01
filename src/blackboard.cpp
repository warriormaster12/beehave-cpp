#include "blackboard.h"
#include "godot_cpp/core/error_macros.hpp"
#include "godot_cpp/variant/dictionary.hpp"
#include "godot_cpp/variant/variant.hpp"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

Blackboard::Blackboard() {
    data = Dictionary();
}

void Blackboard::set_data(Dictionary p_data) {
    data = p_data;
}

void Blackboard::set_value(Variant p_key, Variant p_value) {
    data[p_key] = p_value;
}

Variant Blackboard::get_value(Variant p_key, Variant default_value /*= 0*/) {
    return data.get(p_key, default_value);
}

bool Blackboard::has_value(Variant p_key) {
    return data.has(p_key);
}

void Blackboard::erase_entry(Variant p_key) {
    if (data.has(p_key)) {
        data.erase(p_key);
    } else {
        WARN_PRINT("entry already erased");
    }
}

Blackboard::~Blackboard() {
    ClassDB::bind_method(D_METHOD("set_data", "data"), &Blackboard::set_data);
	ClassDB::bind_method(D_METHOD("get_data"), &Blackboard::get_data);

    //helper functions
    ClassDB::bind_method(D_METHOD("set_value", "key", "value"), &Blackboard::set_value);
	ClassDB::bind_method(D_METHOD("get_value"), &Blackboard::get_value);
    ClassDB::bind_method(D_METHOD("has_value"), &Blackboard::has_value);

    ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "data", PROPERTY_HINT_NONE), "set_data", "get_data");
}

void Blackboard::_bind_methods() {

}