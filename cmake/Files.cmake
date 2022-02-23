function(collect_sources RESULT_SOURCES)
  set(OP_ARGS ${ARGN})
  
  list(LENGTH OP_ARGS OP_COUNT)
  if (${OP_COUNT} GREATER 0)
    list(GET OP_ARGS 0 PATH_PREFIX)
	set(PATH_PREFIX ${${PATH_PREFIX}})
  else()
    set(PATH_PREFIX "")
  endif()
  
  file(GLOB CPP_FILES "${PATH_PREFIX}src/*.cpp")
  file(GLOB MOC_H_FILES "${PATH_PREFIX}include/*.h")
  file(GLOB UI_FILES "${PATH_PREFIX}resource/*.ui")
  file(GLOB RESOURCES "${PATH_PREFIX}resource/*.qrc")

  SET(APP_SOURCES ${CPP_FILES})
  SET(APP_FORM_HEADERS ${MOC_H_FILES})
  SET(APP_UI_FILES ${UI_FILES})
  SET(APP_QRC_SOURCES ${QRC_FILES})
  SET(APP_RESOURCES ${RESOURCE_FILES})

  qt5_add_resources(APP_QRC_SOURCES ${APP_QRC_FILES})
  qt5_wrap_ui(APP_FORM_HEADERS ${APP_UI_FILES})
  qt5_wrap_cpp(APP_HEADERS_MOC ${APP_HEADER_FILES})

  set(${RESULT_SOURCES}
    ${APP_SOURCES}
    ${APP_FORM_HEADERS}
    ${APP_HEADERS_MOC}
    ${APP_QRC_SOURCES}
    ${APP_RESOURCES}
    PARENT_SCOPE
  )

endfunction()

