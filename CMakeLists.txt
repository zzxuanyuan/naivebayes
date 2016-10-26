cmake_minimum_required(VERSION 3.2)
project(NaiveBayes)

set (CMAKE_CXX_STANDARD 11)
SET(CPACK_GENERATOR "TGZ")

add_subdirectory(tinyxml2)
add_subdirectory(naivebayes)
include_directories(naivebayes)
add_subdirectory(examples)

include(CPack)
