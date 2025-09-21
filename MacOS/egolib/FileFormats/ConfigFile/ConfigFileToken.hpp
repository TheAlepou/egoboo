#pragma once

#include "ConfigFile/ConfigFileTokenKind.hpp"
// #include "hll.hpp"

class ConfigFileToken : public idlib::hll::token<ConfigFileTokenKind, ConfigFileTokenKind::Unknown>
{
public:
    ConfigFileToken
        (
            ConfigFileTokenKind kind,
            const idlib::hll::location& startLocation,
            const std::string& lexeme = std::string()
        );
};
