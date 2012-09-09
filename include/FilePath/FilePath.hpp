#ifndef FILEINFO_HPP
#define FILEINFO_HPP

#include <string>
#include <map>

#include <sys/stat.h>

#include "Environment.hpp"

typedef std::map<std::string, std::string> Environmnet;

class FilePath
{
public:
    FilePath(const std::string& path);

    bool exists() const;

    bool isDir() const;
    bool isFile() const;

    const std::string& path();

private:
    std::string expand_(const std::string& path) const;
    void getStatus_(const std::string& path);

    std::string path_;

    bool statusObtained_;
    struct stat pathStatus_;

    int error;

    bool exists_;
};

#endif // FILEINFO_HPP
