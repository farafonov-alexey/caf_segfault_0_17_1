cmake_minimum_required(VERSION 3.2)
project(fruit_test)
set(ARCH "x64") # for test

set(CMAKE_CXX_STANDARD 11)
if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wextra -Wall -pedantic -ftemplate-depth=512 -ftemplate-backtrace-limit=0 -Wno-missing-field-initializers -O3 -DNDEBUG")
elseif (${CMAKE_BUILD_TYPE} STREQUAL Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -Werror")
endif ()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/${ARCH}/${CMAKE_BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

#set(Qt5_DIR $ENV{QT5_DIR_${ARCH}})
set(CAF_ROOT_DIR $ENV{CAF_DIR_${ARCH}})

find_package(CAF COMPONENTS core io test REQUIRED)

if (MINGW)
    list(APPEND CAF_EXTRA_LDFLAGS -lws2_32 -liphlpapi -lpsapi)
endif ()
#add_subdirectory(actor_framework)

include_directories(${CAF_INCLUDE_DIRS})
add_executable(${PROJECT_NAME}
        main.cpp
        )
target_link_libraries(${PROJECT_NAME}
        ${CAF_LIBRARY_IO}
        ${CAF_LIBRARY_CORE}
        ${CAF_EXTRA_LDFLAGS}
        -static-libstdc++
        -static-libgcc
        -static -lpthread
        )
