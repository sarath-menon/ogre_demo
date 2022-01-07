cmake_minimum_required(VERSION 3.0.0)
project(ogre_demo VERSION 0.1.0)

find_package(OGRE REQUIRED COMPONENTS Bites RTShaderSystem CONFIG)

include(CTest)
enable_testing()

add_executable(ogre_demo 
src/main.cpp
src/ogre_demo.cpp
src/scene.cpp
src/lighting.cpp
src/camera.cpp
src/ground.cpp
)

target_include_directories(ogre_demo PUBLIC include)
target_link_libraries(ogre_demo OgreBites OgreRTShaderSystem)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
