#pragma once

#define FUSE_USE_VERSION 31

#include <fuse3/fuse.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <map>

/*-DEVFS_OPERATIONS-*/

int DevFS_initialize(int argc, char *argv[]);

/*-DEVFS_FILE_SYSTEM-*/

class DevFS_Element {
    public:
        std::string name;  // File name

        // stat structure:
        size_t      inode; // File serial number
        mode_t      mode;  // File type and permissions
        size_t      size;  // File size
        size_t      nlink; // File hardlink count

        DevFS_Element(const std::string& name, mode_t mode, size_t size = 0, size_t nlink = 0)
            : name(name), mode(mode), size(size), nlink(nlink) {}
};

class DevFS_File : DevFS_Element {
    public:
        std::string content; // Whole file content

        DevFS_File(const std::string& name, const std::string& content = "", mode_t mode = S_IFREG | 0644)
            : DevFS_Element(name, mode), content(content) {}

        void    Initialize();
};

class DevFS_Directory : DevFS_Element {
    public:
        std::map<std::string, DevFS_Element*> content; // Subdirectories and files

        DevFS_Directory(const std::string& name, mode_t mode = S_IFDIR | 0755)
        : DevFS_Element(name, mode) {}

        void    Initialize();
};

class DevFS_Manager {
    private:
        DevFS_Directory root;
    public:
        DevFS_Manager() : root("/") {}
};
