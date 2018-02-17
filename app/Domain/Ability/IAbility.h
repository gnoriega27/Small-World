//
// Created by Gabriel Noriega on 2018-02-16.
//

#ifndef SMALLWORLD_IABILITY_H
#define SMALLWORLD_IABILITY_H

#include <iostream>
#include "AbilityType.h"

class IAbility {
    std::string const m_name;
    AbilityType const m_abilityType;
    unsigned short int m_tokens;
    bool const m_isRaceAbility;
public:
    IAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : m_name(v_name), m_abilityType(v_abilityType), m_tokens(v_tokens), m_isRaceAbility(v_isRaceAbility) {}

};


// First level or inheritance

class IInitialAbility : public IAbility {
public:
    IInitialAbility(std::string v_name, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::INITIAL, v_tokens, v_isRaceAbility) {}

};

class IActiveAbility : public IAbility {
public:
    IActiveAbility(std::string v_name, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::ACTIVE, v_tokens, v_isRaceAbility) {}
};

class IDeploymentAbility : public IAbility {
public:
    IDeploymentAbility(std::string v_name, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::DEPLOYMENT, v_tokens, v_isRaceAbility) {}
};

class IConquerableAbility : public IAbility {
public:
    IConquerableAbility(std::string v_name, unsigned short int v_tokens,
                        bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::CONQUERABLE, v_tokens, v_isRaceAbility) {}
};

class IRedeploymentAbility : public IAbility {
public:
    IRedeploymentAbility(std::string v_name, unsigned short int v_tokens,
                         bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::REDEPLOYMENT, v_tokens, v_isRaceAbility) {}
};

class ILossAbility : public IAbility {
public:
    ILossAbility(std::string v_name, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), AbilityType::LOSS, v_tokens, v_isRaceAbility) {}
};

class IConquestAbility : public IAbility {
public:
    IConquestAbility(std::string v_name, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::CONQUEST, v_tokens, v_isRaceAbility) {}
};

class IAttackAbility : public IAbility {
public:
    IAttackAbility(std::string v_name, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::ATTACK, v_tokens, v_isRaceAbility) {}
};

class IDefenceAbility : public IAbility {
public:
    IDefenceAbility(std::string v_name, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::DEFENSE, v_tokens, v_isRaceAbility) {}
};

class IVictoryAbility : public IAbility {
public:
    IVictoryAbility(std::string v_name, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::VICTORY, v_tokens, v_isRaceAbility) {}
};

class IEndTurnAbility : public IAbility {
public:
    IEndTurnAbility(std::string v_name, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(v_name, AbilityType::ENDTURN, v_tokens, v_isRaceAbility) {}
};

#endif //SMALLWORLD_IABILITY_H
