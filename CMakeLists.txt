#cmake_minimum_required(VERSION 2.8.5 FATAL_ERROR)
cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)
project(mini-async-log VERSION 1.1.1)

option(USE_BOOST "Use Boost atomic, chrono, cstdint and thread" OFF)
option(STRIP_LOG_DEBUG "Remove this log level and levels less severe during compilation" OFF)
option(STRIP_LOG_TRACE "Remove this log level and levels less severe during compilation" OFF)
option(STRIP_LOG_NOTICE "Remove this log level and levels less severe during compilation" OFF)
option(STRIP_LOG_WARNING "Remove this log level and levels less severe during compilation" OFF)
option(STRIP_LOG_ERROR "Remove this log level and levels less severe during compilation" OFF)
option(STRIP_LOG_CRITICAL "Remove all log levels during compilation" OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CLANG_OR_GCC 1)
else()
    set(CLANG_OR_GCC 0)
endif()

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CLANG_OR_GCC)
      set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
    endif ()
else ()
    set(CMAKE_CXX_STANDARD 11)
endif ()

if(CLANG_OR_GCC)
    set(CMAKE_REQUIRED_DEFINITIONS "-std=c++11")
endif()





if (CMAKE_SYSTEM_NAME MATCHES "Linux")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
elseif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
else ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif (CMAKE_SYSTEM_NAME MATCHES "Linux")


if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # using Clang
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # using GCC
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    # using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # using Visual Studio C++
endif()

#cmake.exe -G "MinGW Makefiles"


if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    MESSAGE(STATUS "current platform: Linux ")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    MESSAGE(STATUS "current platform: Windows")
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    MESSAGE(STATUS "current platform: Mac OS X")
else ()
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif (CMAKE_SYSTEM_NAME MATCHES "Linux")

cmake_host_system_information(RESULT PRETTY_NAME QUERY DISTRIB_PRETTY_NAME)
message(STATUS "${PRETTY_NAME}")

cmake_host_system_information(RESULT DISTRO QUERY DISTRIB_INFO)
foreach(VAR IN LISTS DISTRO)
    message(STATUS "${VAR}=`${${VAR}}`")
endforeach()

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_DEBUG_POSTFIX "d")
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    endif()
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fexec-charset=utf-8 /source-charset=utf-8 /execution-charset=utf-8")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /fexec-charset=utf-8 /source-charset:utf-8 /execution-charset:utf-8")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
    #set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -fexec-charset=GBK")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=utf-8")
endif()
#link_directories(${CMAKE_BINARY_DIR} )

message("CMAKE_C_COMPILER = ${CMAKE_C_COMPILER}")
message("CMAKE_C_COMPILER_VERSION = ${CMAKE_C_COMPILER_VERSION}")
message("CMAKE_CXX_PLATFORM_ID = ${CMAKE_CXX_PLATFORM_ID}")
message("CMAKE_CXX_COMPILER_TARGET = ${CMAKE_CXX_COMPILER_TARGET}")
message("CMAKE_CXX_COMPILER_AR = ${CMAKE_CXX_COMPILER_AR}")
message("CMAKE_C_COMPILER_ABI = ${CMAKE_C_COMPILER_ABI}")
message("CMAKE_C_COMPILER_TARGET = ${CMAKE_C_COMPILER_TARGET}")
message("CMAKE_HOST_SYSTEM = ${CMAKE_HOST_SYSTEM}")
message("CMAKE_HOST_SYSTEM_NAME = ${CMAKE_HOST_SYSTEM_NAME}")
message("CMAKE_VS_PLATFORM_NAME = ${CMAKE_VS_PLATFORM_NAME}")
message("CMAKE_VS_PLATFORM_TOOLSET = ${CMAKE_VS_PLATFORM_TOOLSET}")
message("CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
#message("CMAKE_CXX_COMPILER_TARGET= ${CMAKE_CXX_COMPILER_TARGET}")
message("CMAKE_CXX_COMPILER_ABI= ${CMAKE_CXX_COMPILER_ABI}")
message("CMAKE_CXX_COMPILER_EXTERNAL_TOOLCHAIN= ${CMAKE_CXX_COMPILER_EXTERNAL_TOOLCHAIN}")
message("CMAKE_CXX_COMPILER_ID= ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CXX_COMPILER_ARCHITECTURE_ID= ${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}")
#message("CMAKE_HOST_SYSTEM_NAME= ${CMAKE_HOST_SYSTEM_NAME}")
message("CMAKE_Fortran_FORMAT= ${CMAKE_Fortran_FORMAT}")
message("CMAKE_Fortran_COMPILER= ${CMAKE_Fortran_COMPILER}")
message("CMAKE_Fortran_COMPILER_VERSION= ${CMAKE_Fortran_COMPILER_VERSION}")
message("CMAKE_Fortran_COMPILER_ID= ${CMAKE_Fortran_COMPILER_ID}")


# 改变安装路径可以使用下面的语句，Unix: "/usr/local", Windows: "c:/Program Files/${PROJECT_NAME}" 为默认值，所有的DESTINATION均以此目录为根目录
# set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/mymath)
#set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/../${PROJECT_NAME}_${PROJECT_VERSION}_${CMAKE_HOST_SYSTEM}_${CMAKE_CXX_COMPILER_ID}_${CMAKE_CXX_COMPILER_VERSION}_install)
#set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/../${PROJECT_NAME}_${PROJECT_VERSION}_${CMAKE_CXX_COMPILER_ID}_${CMAKE_CXX_COMPILER_VERSION}_${CMAKE_Fortran_COMPILER_ID}_${CMAKE_Fortran_COMPILER_VERSION}_install)
#set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/../${PROJECT_NAME}_${PROJECT_VERSION}_${CMAKE_HOST_SYSTEM_NAME}_${CMAKE_CXX_PLATFORM_ID}_${CMAKE_CXX_COMPILER_ID}_${CMAKE_CXX_COMPILER_VERSION}_${CMAKE_Fortran_COMPILER_ID}_${CMAKE_Fortran_COMPILER_VERSION}_CXX_${CMAKE_CXX_STANDARD}_${CMAKE_SYSTEM_PROCESSOR}_install)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/../${PROJECT_NAME}_${PROJECT_VERSION}_${CMAKE_CXX_COMPILER_VERSION}_${CMAKE_Fortran_COMPILER_ID}_${CMAKE_Fortran_COMPILER_VERSION}_CXX_${CMAKE_CXX_STANDARD}_${CMAKE_SYSTEM_PROCESSOR}_install)


set(OUTPUT_DIR_KENT   ${CMAKE_BINARY_DIR}/../${PROJECT_NAME}_${PROJECT_VERSION}_${CMAKE_CXX_COMPILER_ID}_${CMAKE_CXX_COMPILER_VERSION}_${CMAKE_Fortran_COMPILER_ID}_${CMAKE_Fortran_COMPILER_VERSION}_CXX_${CMAKE_CXX_STANDARD}_${CMAKE_SYSTEM_PROCESSOR}_bin )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR_KENT})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR_KENT})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR_KENT})

# install
include(CMakePackageConfigHelpers)

# aux_source_directory(./  sourceAll )
# file(GLOB_RECURSE  ./*.cpp  all_source_files )
 file(GLOB_RECURSE all_hpp_files ./*.hpp   )



include(CheckIncludeFileCXX)

if(USE_BOOST)
    find_package(Boost REQUIRED COMPONENTS atomic chrono thread)

    if(Boost_FOUND)
        include_directories(${Boost_INCLUDE_DIRS})
    else()
        message(FATAL_ERROR "Boost not found")
    endif()
else()
    check_include_file_cxx(thread HAVE_STD_THREAD)
    check_include_file_cxx(atomic HAVE_STD_ATOMIC)
    check_include_file_cxx(chrono HAVE_STD_CHRONO)
    check_include_file_cxx(cstdint HAVE_STD_CSTDINT)

    if(NOT HAVE_STD_CSTDINT OR NOT HAVE_STD_ATOMIC OR NOT HAVE_STD_CHRONO OR NOT HAVE_STD_THREAD)
        message(FATAL_ERROR "<atomic>, <cstdint>, <chrono>, and/or <thread> not found")
    endif()
endif()

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")

set(mal_PUBLIC_HEADERS
    "${PROJECT_SOURCE_DIR}/include/mal_log/cfg.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/compile_format_validator.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/decltype_wrap.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/extras/boost_filesystem_list_all_files.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/format_tokens.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/frontend.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/frontend_types.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/frontend_types_convenience_funcs_to_current_namespace.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/mal_interface.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/mal_log.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/mal_private.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/mal_strip.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/serialization/basic_encoder_decoder.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/serialization/exporter.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/serialization/fields.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/serialization/header_data.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/serialization/importer_exporter.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/sync_point.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/timestamp.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/atomic.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/chrono.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/integer.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/integer_bits.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/integer_bits_detail.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/integral_enable_if.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/literal.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/max_align.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/opaque_pod.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/processor_pause.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/queue_backoff_cfg.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/side_effect_assert.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/stack_ostream.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/static_rdbuf.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/system.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/thread.hpp"
    "${PROJECT_SOURCE_DIR}/include/mal_log/util/variadic_macro_arg_count.hpp"
)

set(mal_PRIVATE_HEADERS
    "${PROJECT_SOURCE_DIR}/src/mal_log/async_to_sync.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/backend.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/log_file_register.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/log_writer.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/output.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/queue.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/serialization/byte_stream_convert.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/serialization/importer.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/serialization/printf_modifiers.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/aligned_type.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/calendar_str.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/memory_mpmc_bounded.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/mem_printf.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/mpmc_bounded.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/mpsc.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/on_stack_dynamic.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/placement_new.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/queue_backoff.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/raw_circular_buffer.hpp"
    "${PROJECT_SOURCE_DIR}/src/mal_log/util/safe_bool.hpp"
)

add_definitions(-D_ENABLE_EXTENDED_ALIGNED_STORAGE) # added by Ken. 2024-4-22

set(mal_SOURCES
    "${PROJECT_SOURCE_DIR}/src/mal_log/frontend.cpp"
)

if(STRIP_LOG_DEBUG)
    add_definitions(-DMAL_STRIP_LOG_SEVERITY=0)
elseif(STRIP_LOG_TRACE)
    add_definitions(-DMAL_STRIP_LOG_SEVERITY=1)
elseif(STRIP_LOG_NOTICE)
    add_definitions(-DMAL_STRIP_LOG_SEVERITY=2)
elseif(STRIP_LOG_WARNING)
    add_definitions(-DMAL_STRIP_LOG_SEVERITY=3)
elseif(STRIP_LOG_ERROR)
    add_definitions(-DMAL_STRIP_LOG_SEVERITY=4)
elseif(STRIP_LOG_CRITICAL)
    add_definitions(-DMAL_STRIP_LOG_SEVERITY=5)
endif()

if(BUILD_SHARED_LIBS)
    add_definitions(-DMAL_DYNLIB_COMPILE)
endif()

if(USE_BOOST)
    add_definitions(-DMAL_USE_BOOST_ATOMIC -DMAL_USE_BOOST_CHRONO -DMAL_USE_BOOST_CSTDINT -DMAL_USE_BOOST_THREAD)
endif()

add_library(mini_async_log SHARED ${mal_SOURCES} ${all_hpp_files})

if(USE_BOOST)
    target_link_libraries(mini_async_log ${Boost_LIBRARIES})
endif()

install(TARGETS mini_async_log
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include DESTINATION ${CMAKE_INSTALL_PREFIX} FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY include DESTINATION ${CMAKE_INSTALL_PREFIX} FILES_MATCHING PATTERN "*.h")





#//-----------------------------------------------------------------

target_include_directories(mini_async_log PRIVATE  ${CMAKE_SOURCE_DIR}/include)
set_target_properties(mini_async_log PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/mal_log/mal_log.hpp    )

# 写入库的版本信息
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        mini_async_logConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion
        )

# 将库文件，可执行文件，头文件安装到指定目录
install(TARGETS mini_async_log
        EXPORT mini_async_logTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        PUBLIC_HEADER DESTINATION include
        )

# 将库的相关信息输出为MyMathConfig.cmake，供find_package查找
install(EXPORT mini_async_logTargets
        FILE mini_async_logTargets.cmake
        NAMESPACE mini_async_log::
        DESTINATION lib/cmake/mini_async_log
        )

configure_file(mini_async_logConfig.cmake.in mini_async_logConfig.cmake @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/mini_async_logConfig.cmake"
                "${CMAKE_CURRENT_BINARY_DIR}/mini_async_logConfigVersion.cmake"
        DESTINATION lib/cmake/mini_async_log
        )

    configure_file(mini_async_logconf.h.in mini_async_logconf.h @ONLY)
 install(FILES  ${CMAKE_CURRENT_BINARY_DIR}/mini_async_logconf.h DESTINATION include )



#============================================================================
# Example binaries
#============================================================================
include_directories(include include/mal_log)

add_executable(example test/example.cpp)
target_link_libraries(example mini_async_log)
add_test(example example)

##add_executable(minigzip test/minigzip.c)
#target_link_libraries(minigzip mini_async_log)

if(HAVE_OFF64_T)
    add_executable(example64 test/example.cpp)
    target_link_libraries(example64 mini_async_log)
    set_target_properties(example64 PROPERTIES COMPILE_FLAGS "-D_FILE_OFFSET_BITS=64")
    add_test(example64 example64)
endif()


