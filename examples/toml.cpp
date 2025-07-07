#include "cup_plugin/toml/project.h"
#include <iostream>

namespace data
{
    struct MyDef
    {
        data::Project project;
    };

    TOML_DESERIALIZE(MyDef, {
        TOML_REQUIRE(project);
    });
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <toml_file>" << std::endl;
        return 1;
    }
    try
    {
        auto mydef = data::Deserializer<data::MyDef>::deserialize(toml::parse_file(argv[1]));
        std::cout << "Project name: " << mydef.project.name << std::endl;
        std::cout << "Project version: " << mydef.project.version << std::endl;
        std::cout << "Project type: " << mydef.project.type << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}