//
// Created by Gabriel Noriega on 2018-02-15.
//

#ifndef SMALLWORLD_TOKEN_H
#define SMALLWORLD_TOKEN_H

#include "TokenType.h"
#include "TokenSubtype.h"

struct Token {
    TokenType const m_type;
    TokenSubtype const m_subtype;
    bool m_inDecline{false};
    bool m_transient{false};

    Token(TokenType v_type, TokenSubtype v_subtype) : m_type(v_type), m_subtype(v_subtype) {}

    ~Token() = default;

    void goInDecline() { m_inDecline = true; }

    void goOutDecline() { m_inDecline = false; }

    void setTransient(bool state) { m_transient = state; }
};


#endif //SMALLWORLD_TOKEN_H