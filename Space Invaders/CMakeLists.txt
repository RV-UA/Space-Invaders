CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(SpaceInvaders)
SET(CMAKE_CXX_FLAGS "-Wall")
ADD_DEFINITIONS(
    -std=c++11
)

ADD_SUBDIRECTORY(src)
