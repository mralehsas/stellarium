set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

ADD_EXECUTABLE(testALBAZPluginSmoke
     testPluginSmoke.hpp
     testPluginSmoke.cpp
)
TARGET_LINK_LIBRARIES(testALBAZPluginSmoke
     Qt${QT_VERSION_MAJOR}::Test
     ALBAZCrescent-static
     stelMain
)
ADD_TEST(testALBAZPluginSmoke testALBAZPluginSmoke)
SET_TARGET_PROPERTIES(testALBAZPluginSmoke PROPERTIES FOLDER "plugins/ALBAZCrescent/src/test")
