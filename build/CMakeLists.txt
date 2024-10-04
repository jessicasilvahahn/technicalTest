cmake_minimum_required(VERSION 3.22.1)

project(technicalTest LANGUAGES CXX)

if(DEFINED ENV{VOLUME_PATH})
    set(WORK_DIR $ENV{VOLUME_PATH})
else()
    message(WARNING "WORK_DIR is not set!")
endif()

# Locate GTest
find_package(GTest REQUIRED)
find_package (Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
    ${WORK_DIR}/main.cpp
    ${WORK_DIR}/server/Server.cpp
    ${WORK_DIR}/server/Session.cpp
    ${WORK_DIR}/server/DataReceiver.cpp
    ${WORK_DIR}/server/FileWriter.cpp
    ${WORK_DIR}/client/Client.cpp
    ${WORK_DIR}/file/File.cpp
)

add_executable(service ${SOURCE_FILES})
add_executable(runTests ${WORK_DIR}/tests/tests.cpp ${WORK_DIR}/client/Client.cpp ${WORK_DIR}/file/File.cpp)
add_executable(mergeFiles ${WORK_DIR}/tests/mergeFiles.cpp)

target_link_libraries(service Boost::system pthread)
target_link_libraries(runTests ${GTEST_LIBRARIES} ${Boost_LIBRARIES} pthread)

install(TARGETS service DESTINATION ${WORK_DIR})
install(TARGETS runTests DESTINATION ${WORK_DIR})
install(TARGETS mergeFiles DESTINATION ${WORK_DIR})