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
            : m_isRaceAbility(v_isRaceAbility) {}
};

class IInitialAbility : IAbility {
public:
    IInitialAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}

};

class IActiveAbility : IAbility {
public:
    IActiveAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

class IDeploymentAbility {
public:
    IDeploymentAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

class IConquerableAbility : IAbility {
public:
    IConquerableAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens,
                        bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

class IRedeploymentAbility : IAbility {
public:
    IRedeploymentAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens,
                         bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

class ILossAbility : IAbility {
public:
    ILossAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

class IConquestAbility : IAbility {
public:
    IConquestAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

class IAttackAbility : IAbility {
public:
    IAttackAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

class IDefenceAbility : IAbility {
public:
    IDefenceAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

class IVictoryAbility : IAbility {
public:
    IVictoryAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

class IEndTurnAbility : IAbility {
public:
    IEndTurnAbility(std::string v_name, AbilityType v_abilityType, unsigned short int v_tokens, bool v_isRaceAbility)
            : IAbility(std::string(), v_abilityType, v_tokens, v_isRaceAbility) {}
};

#endif //SMALLWORLD_IABILITY_H
