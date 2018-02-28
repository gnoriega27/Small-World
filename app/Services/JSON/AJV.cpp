//
// Created by Philippe Hebert on 2018-02-16.
//
#include <nlohmann/json.hpp>
#include "AJV.h"

using nlohmann::json;

namespace SmallWorld {
  std::function<bool(json*)> AJV::compile(json* schema) {
    return [](json* map){ return true; };
  };
  bool AJV::validate(json* schema, json* data){ return true; };
};
