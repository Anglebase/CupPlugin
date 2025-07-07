#include "cup_plugin/interface.h"
#include <iostream>

class Plugin : public IPlugin
{
public:
    virtual std::string getName(std::optional<std::string> &except) const
    {
        std::cout << "Plugin::getName" << std::endl;
        return "Plugin";
    };

    virtual int run_new(const NewData &data, std::optional<std::string> &except)
    {
        std::cout << "Plugin::run_new" << std::endl;
        return 0;
    };

    virtual std::string gen_cmake(const CMakeContext &context, bool is_dependency, std::optional<std::string> &except)
    {
        std::cout << "Plugin::gen_cmake" << std::endl;
        return "";
    };

    virtual fs::path run_project(const RunProjectData &data, std::optional<std::string> &except)
    {
        std::cout << "Plugin::run_project" << std::endl;
        return "";
    };
    virtual std::optional<std::string> get_target(const RunProjectData &data, std::optional<std::string> &except) const
    {
        std::cout << "Plugin::get_target" << std::endl;
        return std::nullopt;
    };

    virtual int show_help(const cmd::Args &command, std::optional<std::string> &except) const
    {
        std::cout << "Plugin::show_help" << std::endl;
        return 0;
    };
    virtual int execute(const cmd::Args &command, std::optional<std::string> &except)
    {
        except = "This plugin does not support command execution.";
        return -1;
    };
};

EXPORT_PLUGIN(Plugin);

int main() {
    auto plugin = createPlugin();
    std::optional<std::string> except;
    std::cout << plugin->getName(except) << std::endl;
    destroyPlugin(plugin);
    return 0;
}