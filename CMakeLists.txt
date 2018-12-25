cmake_minimum_required(VERSION 3.10.2)
project(HuffmanCoding)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HuffmanCoding
        FrequencyCounter.cpp
        FrequencyCounter.h
        main.cpp
        Node.cpp Node.h
        Huffman.cpp Huffman.h HuffmanUtility.cpp HuffmanUtility.h)
