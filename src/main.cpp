#include "DevFS.hpp"

int main(int argc, char *argv[])
{
    fprintf(stdout, "Starting DevFS\n");
    fflush(stdout);

    int ret = DevFS_initialize(argc, argv);

    fprintf(stdout, "Exiting DevFS\n");
    fflush(stdout);

    return ret;
}
