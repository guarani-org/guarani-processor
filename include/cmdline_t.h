//
// Created by gui on 7/18/20.
//

#ifndef GUARANI_PROCESSOR_CMDLINE_T_H
#define GUARANI_PROCESSOR_CMDLINE_T_H

#include <string>
#include <string_view>
#include <cxxopts.hpp>

class cmdline_t {
public:
    cmdline_t(const cmdline_t &) = delete;

    cmdline_t(cmdline_t &&) = delete;

    static cmdline_t &get() noexcept {
        static cmdline_t instance;
        return instance;
    }

    bool parse(int agc, char **argv) noexcept;

    static std::string_view input()noexcept;
    static std::string_view output()noexcept;
    static std::string_view conf_file()noexcept;

private:
    cmdline_t() = default;

    ~cmdline_t() = default;

    std::string _input;
    std::string _output_name;
    std::string _configuration_file;
};


#endif //GUARANI_PROCESSOR_CMDLINE_T_H
