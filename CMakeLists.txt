cmake_minimum_required (VERSION 3.8)

set(PROJ_NAME "IntergalacticParcelService")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(${PROJ_NAME})


#simple glob on all source files, yolo
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")


#windows/MSVC compiler warnings when writting C on a modern C++ compiler and ignoring SAL-annotation
set(DISABLE_USELESS_MICROSLOB_WARNINGS  /wd28251 /wd5105)



add_executable(${PROJ_NAME} WIN32 ${SOURCE_FILES})



#headers, compiler options, libraries
target_include_directories(${PROJ_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include" )
target_compile_definitions(${PROJ_NAME} PRIVATE UNICODE _UNICODE)
target_compile_options(${PROJ_NAME} PRIVATE /GR- /EHs- ${DISABLE_USELESS_MICROSLOB_WARNINGS})
target_link_libraries(${PROJ_NAME} openGL32 gdi32 user32 kernel32 xaudio2.lib winmm.lib)

#external headers
target_include_directories(${PROJ_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/external" )
