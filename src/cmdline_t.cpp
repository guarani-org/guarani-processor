//
// Created by gui on 7/18/20.
//

#include "cmdline_t.h"

bool cmdline_t::parse(int agc, char **argv) noexcept {
    cxxopts::Options options("Guarani-Processor",
                             "Process data from guarani logger");
    try {
        options.add_options()
                ("i,input", "input can be a file or a folder", cxxopts::value<std::string>())
                ("o,output", "output file", cxxopts::value<std::string>())
                ("c,config", "configuration file", cxxopts::value<std::string>());

        auto result = options.parse(agc, argv);

        _input = result["i"].as<std::string>();
        _output_name = result["o"].as<std::string>();
        _configuration_file = result["c"].as<std::string>();
        return true;

    } catch (cxxopts::OptionException &e) {
        std::cout << e.what() << std::endl;
        return false;
    }


}

std::string_view cmdline_t::input() noexcept {
    auto & instance = cmdline_t::get();
    return instance._input;
}

std::string_view cmdline_t::output() noexcept {
    auto & instance = cmdline_t::get();
    return instance._output_name;
}

std::string_view cmdline_t::conf_file() noexcept {
    auto & instance = cmdline_t::get();
    return instance._configuration_file;
}
