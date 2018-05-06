cmake_minimum_required(VERSION 3.10)
project(TrianglePath)

set(CMAKE_CXX_STANDARD 11)

set(TrianglePath main.cpp Logic/TerminalProgram.cpp Logic/TerminalProgram.h Library/FileReader.cpp Library/FileReader.h Logic/MinimalTrianglePath.cpp Logic/MinimalTrianglePath.h)
add_executable(TrianglePath ${TrianglePath})
