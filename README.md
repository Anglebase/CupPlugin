# Cup Plugin

This is the interface of Cup Plugin. Developper can use this interface to implement Cup Plugin and publish it.

## Example

```cpp
#include "cup_plugin/interface.h"
#include <iostream>

class Plugin : public IPlugin
{
public:
    virtual std::string getName(std::optional<std::string> &except) const
    {
        // This function will be called when the plugin name needs to be obtained.
        // Under normal circumstances, it should return its own file name.
        std::cout << "Plugin::getName" << std::endl;
        return "Plugin";
    };

    virtual int run_new(const NewData &data, std::optional<std::string> &except)
    {
        // This function is called when running this plugin through the `new` sub command.
        // This function is used to generate project templates or demo.
        std::cout << "Plugin::run_new" << std::endl;
        return 0;
    };

    virtual std::string gen_cmake(const CMakeContext &context, bool is_dependency, std::optional<std::string> &except)
    {
        // When the build sub command is called, this function will be called to generate the corresponding CMake code snippet, and the uniqueness of the name should be ensured during the processing.
        std::cout << "Plugin::gen_cmake" << std::endl;
        return "";
    };

    
    virtual std::string gen_cmake_global(const CMakeContext &context, bool is_dependency, std::optional<std::string> &except) {
        // This function is used to generate the global CMake code snippet, which will be inserted before the project() command.
        std::cout << "Plugin::gen_cmake_global" << std::endl;
        return "";
    }

    virtual fs::path run_project(const RunProjectData &data, std::optional<std::string> &except)
    {
        // When running the run command, this function should return the path of the executable file to be run.
        std::cout << "Plugin::run_project" << std::endl;
        return "";
    };
    virtual std::optional<std::string> get_target(const RunProjectData &data, std::optional<std::string> &except) const
    {
        // In order to improve the construction speed, it is used to obtain the target that needs to be built, and its return value will be used as the -- target parameter of the cmake command
        std::cout << "Plugin::get_target" << std::endl;
        return std::nullopt;
    };

    virtual int show_help(const cmd::Args &command, std::optional<std::string> &except) const
    {
        // Used to display help information for plugins.
        std::cout << "Plugin::show_help" << std::endl;
        return 0;
    };
    virtual int execute(const cmd::Args &command, std::optional<std::string> &except)
    {
        // Used to execute plugin specific commands.
        except = "This plugin does not support command execution.";
        return -1;
    };
};

// Export plugin calling interface.
// Cup creates instances through it.
EXPORT_PLUGIN(Plugin);
```