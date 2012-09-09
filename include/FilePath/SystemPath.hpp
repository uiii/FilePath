#ifndef SYSTEMPATH_HPP
#define SYSTEMPATH_HPP

#include <string>
#include <vector>

class SystemPath
{
public:
    static void init(int argc, char* argv[], const std::string& appName);

    static std::string homePath();
    static std::string dataPath(const std::string& dataDir = "");

private:
    static std::string appName_;
    static std::vector<std::string> dataPaths_;
};

#endif //SYSTEMPATH_HPP
