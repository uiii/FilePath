#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <string>
#include <map>

class Environment
{
public:
    Environment();

    static std::string get(const std::string& var);
    static void set(const std::string& var, const std::string& value);

private:
    typedef std::map<std::string, std::string> Vars;
    static Vars vars_;
};

#endif // ENVIRONMENT_HPP
