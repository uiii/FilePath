#include "SystemPath.hpp"

#include <cstdlib>
#include <sys/stat.h>

#include "FilePath.hpp"

void SystemPath::init(int argc, char* argv[], const std::string& appName)
{
    appName_ = appName;
    Environment::set("APP_NAME", appName_);
}

std::string SystemPath::homePath()
{
    return Environment::get("HOME");
}

std::string SystemPath::dataPath(const std::string& dataDir)
{
    for(const std::string& path : dataPaths_)
    {
        FilePath fileInfo(path);
        if(fileInfo.isDir())
        {

        }
    }

    return "/usr/share/" + appName_ + "/" + dataDir;
}
