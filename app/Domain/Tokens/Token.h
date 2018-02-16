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
    bool const m_inDecline;
    bool const m_transient;

    Token(TokenType v_type, TokenSubtype v_subtype) : m_type(v_type), m_subtype(v_subtype), m_inDecline(false),
                                                      m_transient(false) {}

    Token(TokenType v_type, TokenSubtype v_subtype, bool v_transient) : m_type(v_type), m_subtype(v_subtype),
                                                                        m_inDecline(false), m_transient(v_transient) {}

    ~Token() = default;

};


#endif //SMALLWORLD_TOKEN_H