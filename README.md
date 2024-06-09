# [DevFS] - FUSE file system for programming project creation

The goal of this project is to create a FUSE-based file system that streamlines project creation by automatically generating files with predefined templates based on their names. This project aims to make developers more productive by cutting down on repetitive setup tasks, with a focus on being easy to use and fitting smoothly into existing workflows.

## Key Features

1. **Comprehensive Logging:**
   - All changes are logged in a log file with the following information:
      - Time stamps &rarr; For tracking when the change was made

2. **Template System with ':' Syntax:**
   - **File Level Commands** *(all of them will adapt depending on the file extension)*:
       - `:main` &rarr; File with a simple main function, which is also adjustable.
       - `:header` &rarr; Header file with customized include guards
       - `:class` &rarr; Creates a class-structured file, adjusting based on the output file extension.
   - **Directory Level Commands:**
     - `:makefile` &rarr; Makefile adapted file structure:
       - `src/main.cpp` 
       - `inc/<project_name>.hpp`
       - `Makefile`
       - `README.md`

## Dependencies

`sudo apt-get update`

`sudo apt-get install build-essential pkg-config libfuse3-dev fuse3`

## How to use

`make mount <mount_dir>` *(Creates a virtual mount with extended functionality)*

`make unmount <mount_dir>` *(Unmount the FUSE filesystem)*

`make unmount_all` *(Unmounts all directories mounted with the executable)*

`make status` *(Gives information about the mounted directories, if indeed there are)*

## Additional Resources

   - [MQH Blog - Writing a Simple Filesystem Using FUSE in C](https://www.maastaar.net/fuse/linux/filesystem/c/2016/05/21/writing-a-simple-filesystem-using-fuse/)
   - [libfuse - fuse_operations Struct Reference](https://libfuse.github.io/doxygen/structfuse__operations.html)
