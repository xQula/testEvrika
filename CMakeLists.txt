cmake_minimum_required(VERSION 3.7.0)

include_guard(GLOBAL)

project(testEvrika
  VERSION 0.0.1
  DESCRIPTION Description
  HOMEPAGE_URL www.uav.radar-mms.com/gitlab
  LANGUAGES C CXX
)

if("${CMAKE_GENERATOR}" MATCHES "^Visual Studio")
  set(CMAKE_GENERATOR_PLATFORM x64 CACHE STRING  FORCE)
endif()

set_target_properties( PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS OFF
)

 set(CMAKE_AUTOMOC ON)
 set(CMAKE_AUTORCC ON)
 set(CMAKE_AUTOUIC ON)

 find_package(QT NAMES Qt5 COMPONENTS Core)
 find_package(Qt${QT_VERSION_MAJOR} COMPONENTS  Widgets)


add_executable(${PROJECT_NAME}
        src/c++/widget/mainWidget.cc
        src/c++/widget/mainWidget.h
        src/c++/widget/secondWidget.cc
        src/c++/widget/secondWidget.h
        src/c++/widget/BaseWidget.cc
        src/c++/widget/BaseWidget.h)

target_sources(${PROJECT_NAME}
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/c++/main.cc

)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/c++
)
if(WIN32 AND ${CMAKE_CXX_COMPILER_ID} MATCHES "GNU|Clang|Mingw|MINGW")
  message(STATUS "[${PROJECT_NAME}] adding -mwindows linker opt (${CMAKE_CXX_COMPILER_ID})")
  target_link_options(${PROJECT_NAME} PRIVATE -mwindows)
endif()

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    -DCMAKE_TARGET_NAME=${PROJECT_NAME}
    -DCMAKE_PROJECT_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    -DCMAKE_PROJECT_VERSION_MINOR=${PROJECT_VERSION_MINOR}
    -DCMAKE_PROJECT_VERSION_PATCH=${PROJECT_VERSION_PATCH}
    -DCMAKE_API_TARGET_NAME=${PROJECT_NAME}::api
    -DCMAKE_API_PROJECT_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    -DCMAKE_API_PROJECT_VERSION_MINOR=${PROJECT_VERSION_MINOR}
    -DCMAKE_API_PROJECT_VERSION_PATCH=${PROJECT_VERSION_PATCH}
)

if(WIN32)
  add_custom_command(TARGET ${PROJECT_NAME} 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    COMMAND_EXPAND_LISTS
  )
endif()


