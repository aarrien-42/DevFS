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

## How to use

`make run <mount_dir>` *(Creates a virtual mount with extended functionality)*

## Additional Resources
