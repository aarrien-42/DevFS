#include "DevFS.hpp"

// Description: Shows information about an specific file or directory
// Triggers: 'stat' or 'ls -l'
static int DevFS_getattr(const char *path, struct stat *st, struct fuse_file_info *fi)
{
    fprintf(stdout, "DevFS_getattr called with path: %s\n", path);
    fflush(stdout);
    
    st->st_uid = getuid(); // Owner of the file
    st->st_uid = getgid(); // Owner group of the file
    st->st_atime = time( NULL ); // Last access time
    st->st_mtime = time( NULL ); // Last modification time

    bool isRoot = !strcmp(path, "/");
    if (isRoot) {
        st->st_mode = S_IFDIR | 0755; // File type (regular file, directory, etc.) and permissions
        st->st_nlink = 2; // Number of hardlinks (file names or references to the same file)
    } else {
        st->st_mode = S_IFREG | 0644;
        st->st_nlink = 1;
        st->st_size = 1024; // Size of the file in bytes
    }

    return 0;
}

// Triggers: 'open' or 'fopen'
static int DevFS_open(const char *path, struct fuse_file_info *fi)
{
    fprintf(stdout, "DevFS_open called with path: %s\n", path);
    fflush(stdout);

    return 0;
}

// Description: Reads the content of a specific file
// Triggers: 'read' or 'cat'
static int DevFS_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi)
{
    fprintf(stdout, "DevFS_read called with path: %s, size: %zu, offset: %ld\n", path, size, offset);
    fflush(stdout);

    return 0;
}

// Description: Lists the files/directories which are available inside a specific directory
// Triggers: 'ls' or 'find'
static int DevFS_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi, enum fuse_readdir_flags flags)
{
    fprintf(stdout, "DevFS_readdir called with path: %s\n", path);
    fflush(stdout);

    filler(buf, ".", NULL, 0, FUSE_FILL_DIR_PLUS);
    filler(buf, "..", NULL, 0, FUSE_FILL_DIR_PLUS);

    bool isRoot = !strcmp(path, "/");
    if (isRoot) {
        filler(buf, "file.txt", NULL, 0, FUSE_FILL_DIR_PLUS);
    }
    return 0;
}

static struct fuse_operations DevFS_oper = {
    .getattr = DevFS_getattr,
    .open    = DevFS_open,
    .read    = DevFS_read,
    .readdir = DevFS_readdir,
};

int DevFS_initialize(int argc, char *argv[]) {
    return fuse_main(argc, argv, &DevFS_oper, NULL);
}
