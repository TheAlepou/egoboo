#pragma once

#include "SpawnFile/SpawnFileTokenKind.hpp"
// #include "hll.hpp"

class SpawnFileToken : public idlib::hll::token<SpawnFileTokenKind, SpawnFileTokenKind::Unknown>
{
public:
    SpawnFileToken
        (
            SpawnFileTokenKind kind,
            const idlib::hll::location& startLocation,
            const std::string& lexeme = std::string()
        );
};
