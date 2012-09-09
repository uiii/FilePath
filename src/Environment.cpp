#include "Environment.hpp"

#include <stdexcept>

#include <cstdlib>

Environment::Environment()
{
}

std::string Environment::get(const std::string& var)
{
    std::string value;

    Vars::iterator it = vars_.find(var);
    if(it == vars_.end())
    {
        char* env = std::getenv(var.c_str());
        if(env)
        {
            value = env;
        }
        else
        {
            throw std::runtime_error("Variable " + var + " is not set");
        }
    }
    else
    {
        value = it->second;
    }

    return value;
}

void Environment::set(const std::string &var, const std::string &value)
{
    vars_[var] = value;
}
