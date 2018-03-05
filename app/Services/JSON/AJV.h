//
// Created by Philippe Hebert on 2018-02-16.
//
#ifndef SMALLWORLD_AJV_H
#define SMALLWORLD_AJV_H

#include <nlohmann/json.hpp>

using nlohmann::json;

namespace SmallWorld {
  class AJV {
  public:
    std::function<bool(json*)> compile(json* schema);
    bool validate(json* schema, json* data);
    json errors;
  private:
    json m_schema;
    std::function<bool(json*)> m_validator;
  };
}

#endif // SMALLWORLD_AJV_H
