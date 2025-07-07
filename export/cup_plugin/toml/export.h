#pragma once

#include "cup_plugin/toml/trait.h"

namespace data
{
    struct Export
    {
        std::optional<fs::path> compile_commands;
    };

    TOML_DESERIALIZE(Export, {
        TOML_OPTIONS(compile_commands);
    });
}