cmake_minimum_required(VERSION 3.27)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_executable(project main.cpp
        BoutiqueManager.h
        BoutiqueManager.cpp
        boutique.cpp
        inventory.h
        inventory.cpp
        product.cpp
        product.h
        product.cpp
        children.h
        male.cpp
        female.cpp
        female.h
        children.cpp
        male.h)
