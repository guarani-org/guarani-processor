cmake_minimum_required(VERSION 3.0.0)
project(guarani-processor   VERSION 0.1.0
                            DESCRIPTION "Process guarani logger data files"
                            LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory("${PROJECT_SOURCE_DIR}/submodules/cxxopts")
add_subdirectory("${PROJECT_SOURCE_DIR}/submodules/pugixml")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

enable_testing()

add_executable(gniproc src/main.cpp src/cmdline_t.cpp include/cmdline_t.h)
target_include_directories(gniproc PRIVATE "include" "submodules/cxxopts/include")

set_target_properties(gniproc   PROPERTIES  CMAKE_CXX_STANDARD 17
                                            CXX_STANDARD_REQUIRED YES
                                            CXX_EXTENSIONS NO)

target_link_libraries(gniproc PRIVATE Threads::Threads)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
