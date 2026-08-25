INCLUDE_DIRECTORIES(.)

LINK_DIRECTORIES(${BUILD_DIR}/src)

SET(ALBAZCrescent_SRCS
     ALBAZCrescent.hpp
     ALBAZCrescent.cpp
)

ADD_LIBRARY(ALBAZCrescent-static STATIC ${ALBAZCrescent_SRCS})
SET_TARGET_PROPERTIES(ALBAZCrescent-static PROPERTIES OUTPUT_NAME "ALBAZCrescent")
TARGET_LINK_LIBRARIES(ALBAZCrescent-static
     Qt${QT_VERSION_MAJOR}::Core
     Qt${QT_VERSION_MAJOR}::Gui
     Qt${QT_VERSION_MAJOR}::Widgets
)
SET_TARGET_PROPERTIES(ALBAZCrescent-static PROPERTIES COMPILE_FLAGS "-DQT_STATICPLUGIN")
ADD_DEPENDENCIES(AllStaticPlugins ALBAZCrescent-static)
SET_TARGET_PROPERTIES(ALBAZCrescent-static PROPERTIES FOLDER "plugins/ALBAZCrescent")

# Import ALBAZ from a host translation unit so Qt keeps and registers the
# static plugin even though Stellarium's src target is configured first.
TARGET_SOURCES(stelMain PRIVATE ALBAZCrescentStaticImport.cpp)
TARGET_LINK_LIBRARIES(stelMain PUBLIC ALBAZCrescent-static)

IF(ENABLE_TESTING)
     ADD_SUBDIRECTORY(test)
ENDIF()
