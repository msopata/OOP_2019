cmake_minimum_required(VERSION 3.10)
project(08_fake_mock_or_stub)

set(HEADERS include/Point.h include/Space.h include/TimeImpl.h include/Universe.h include/ObserverImpl.h include/SpaceImpl.h include/Time.h include/Observer.h)
set(SOURCES src/TimeImpl.cpp src/Universe.cpp src/ObserverImpl.cpp src/SpaceImpl.cpp)

add_library(08_fake_mock_or_stub_lib ${HEADERS} ${SOURCES})
target_include_directories(08_fake_mock_or_stub_lib PUBLIC include)

add_executable(08_fake_mock_or_stub src/main.cpp)
target_link_libraries(08_fake_mock_or_stub 08_fake_mock_or_stub_lib)

add_subdirectory(external)
add_subdirectory(test)
add_subdirectory(uml)
