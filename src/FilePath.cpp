#include "FilePath.hpp"

#include <list>
#include <sstream>
#include <functional>

#include <cerrno>

#include <iostream>

#include <boost/xpressive/xpressive_static.hpp>

typedef std::list<std::string> StringList;

FilePath::FilePath(const std::string& path):
    statusObtained_(false),
    exists_(false)
{
    path_ = expand_(path);
    getStatus_(path);
}

bool FilePath::exists() const
{
    return exists_;
}

bool FilePath::isDir() const
{
    return exists() && S_ISDIR(pathStatus_.st_mode);
}

bool FilePath::isFile() const
{
    return exists() && S_ISREG(pathStatus_.st_mode);
}

const std::string& FilePath::path()
{
    return path_;
}

std::string FilePath::expand_(const std::string& path) const
{
    using namespace boost::xpressive;
    sregex variableRegEx = "$" >> (s1 = +_w);
    sregex bracketedVariableRegEx = "${" >> (s1 = +_w) >> "}";

    auto expandVariable = [](const smatch& match) -> std::string
    {
        try
        {
            return Environment::get(match[1].str());
        }
        catch(...)
        {
            return match[0].str();
        }
    };

    std::string expandedpath = path;
    expandedpath = regex_replace(expandedpath, variableRegEx, expandVariable);
    expandedpath = regex_replace(expandedpath, bracketedVariableRegEx, expandVariable);

    return expandedpath;
}

void FilePath::getStatus_(const std::string& path)
{
    if(statusObtained_)
    {
        return;
    }

    int result = stat(path.c_str(), &pathStatus_);

    if(result == -1)
    {
        exists_ = false;
    }
    else
    {
        exists_ = true;
    }
}
