cmake_minimum_required(VERSION 3.0.0)
project(guarani-processor   VERSION 0.1.0
                            DESCRIPTION "Process guarani logger data files"
                            LANGUAGES CXX)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

enable_testing()

add_executable(gniproc src/main.cpp)
target_include_directories(gniproc PRIVATE "include")
set_target_properties(gniproc   PROPERTIES  CMAKE_CXX_STANDARD 17
                                            CXX_STANDARD_REQUIRED YES
                                            CXX_EXTENSIONS NO)
target_link_libraries(gniproc PRIVATE Threads::Threads)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
