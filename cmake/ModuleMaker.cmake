function(create_module MODULE_NAME MODULE_LIBS)

#-----------------------------------------------------------------------------
# Setting variables.
#-----------------------------------------------------------------------------

set(MODULE_NAME CdsProthesis)
set(LIB_MODE PUBLIC)
set(LIBS 
  Qt5::Widgets 
  Qt5::Xml
  ${VTK_LIBRARIES}
  ${CTK_LIBRARIES}
  ${GDCM_LIBRARIES}
  MitkCore
  MitkQtWidgets
  CdsCore
)

#-----------------------------------------------------------------------------
# 
#-----------------------------------------------------------------------------

project(${MODULE_NAME})

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
# Include module files.
#-----------------------------------------------------------------------------

include(files.cmake)

set(_app_options)
if(${PROJECT_NAME}_SHOW_CONSOLE_WINDOW)
  list(APPEND _app_options SHOW_CONSOLE)
endif()

qt5_add_resources(QRC_SOURCES ${QRC_FILES})
qt5_wrap_ui(FORM_HEADERS ${UI_FILES})
qt5_wrap_cpp(HEADERS_MOC ${MOC_H_FILES})

set(MODULE_SOURCES
  ${CPP_FILES}
  ${FORM_HEADERS}
  ${HEADERS_MOC}
  ${QRC_SOURCES}
  ${RESOURCES}
)

#-----------------------------------------------------------------------------
# Process of module targeting.
#-----------------------------------------------------------------------------

add_library(${MODULE_NAME} STATIC ${MODULE_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
  include
)

target_include_directories(${APP_NAME} PUBLIC
  include
  ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${MODULE_NAME} ${LIB_MODE} ${LIBS})

endfunction()