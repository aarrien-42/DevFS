#define FUSE_USE_VERSION 31

#include <fuse3/fuse.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

static const char *hello_str = "Hello World!\n";
static const char *hello_path = "/hello";

static int DevFS_getattr(const char *path, struct stat *stbuf, struct fuse_file_info *fi)
{
    return 0;
}

static int DevFS_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fi, enum fuse_readdir_flags flags)
{
    return 0;
}

static int DevFS_open(const char *path, struct fuse_file_info *fi)
{
    return 0;
}

static int DevFS_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi)
{
    return 0;
}

static struct fuse_operations DevFS_oper = {
    .getattr = DevFS_getattr,
    .open    = DevFS_open,
    .read    = DevFS_read,
    .readdir = DevFS_readdir,
};

int main(int argc, char *argv[])
{
    return fuse_main(argc, argv, &DevFS_oper, NULL);
}
