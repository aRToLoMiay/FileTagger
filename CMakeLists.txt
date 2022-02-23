cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set(APP_NAME FileTagger)

project(${APP_NAME})

#-----------------------------------------------------------------------------
# Options
#-----------------------------------------------------------------------------

set (CMAKE_MODULE_PATH 
  "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake"
)

#-----------------------------------------------------------------------------
# Qt
#-----------------------------------------------------------------------------

find_package(Qt5 COMPONENTS 
  Concurrent 
  Core 
  Gui 
  OpenGL
  Script
  UiTools
  WebEngine
  Widgets 
  Xml
  XmlPatterns
  REQUIRED
)

#-----------------------------------------------------------------------------
# Setting variables.
#-----------------------------------------------------------------------------

set(LIB_MODE PUBLIC)
set(LIBS 
  Qt5::Core 
  Qt5::Gui 
  Qt5::Widgets 
  Qt5::Xml
)

#-----------------------------------------------------------------------------
# 
#-----------------------------------------------------------------------------

project(${APP_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(AUTOGEN_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_AUTOUIC_SEARCH_PATHS 
  ${CMAKE_AUTOUIC_SEARCH_PATHS} 
  ${CMAKE_CURRENT_SOURCE_DIR}/resource
)

#-----------------------------------------------------------------------------
# Files collecting.
#-----------------------------------------------------------------------------

include(Files)
collect_sources(APP_SOURCES)

#-----------------------------------------------------------------------------
# Process of application targeting.
#-----------------------------------------------------------------------------

add_executable(${APP_NAME} ${APP_SOURCES})
set_property (DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_NAME})

target_include_directories(${APP_NAME} PUBLIC
  include
)

target_link_libraries(${APP_NAME} ${LIB_MODE} ${LIBS})
