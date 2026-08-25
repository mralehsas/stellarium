IF(WIN32 AND NOT MSVC)
     STRING(APPEND CMAKE_EXE_LINKER_FLAGS " -Wl,--enable-runtime-pseudo-reloc")
ENDIF()

IF (STELLARIUM_GUI_MODE STREQUAL "None")
     ADD_DEFINITIONS(-DNO_GUI)
ENDIF()

ADD_DEFINITIONS(-DQT_PLUGIN)
ADD_DEFINITIONS(-DQT_DLL)
ADD_DEFINITIONS(-D_REENTRANT)

# ALBAZ Crescent is developed on an isolated Stellarium 26.2 branch.
# Keep the host plugin registry untouched while the feature is under development.
SET(USE_PLUGIN_ALBAZCRESCENT 1 CACHE BOOL "Define whether the ALBAZCrescent plugin should be created.")
LIST(APPEND STELLARIUM_PLUGINS ALBAZCrescent)

FOREACH(NAME ${STELLARIUM_PLUGINS})
     STRING(TOUPPER ${NAME} NAME_UP)
     IF(USE_PLUGIN_${NAME_UP})
          ADD_SUBDIRECTORY(${NAME})
     ENDIF()
ENDFOREACH()
