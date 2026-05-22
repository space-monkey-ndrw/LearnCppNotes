cmake_minimum_required(VERSION 3.10)
project(LearnCppNotesWorkspace)

# Set global compiler standards for all subfolders
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tell CMake to discover and include your subfolders
add_subdirectory(HelloWorld)
add_subdirectory(MultiplyByTwo)
add_subdirectory(PrintLanguageStandard)