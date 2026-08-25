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

# Scientific foundation types are intentionally tested in isolation.
# Keeping this target independent of stelMain/ALBAZCrescent-static makes the
# RED/GREEN TDD cycle fast and ensures failures originate in the scientific
# types themselves rather than unrelated host-link dependencies.
ADD_EXECUTABLE(testALBAZScientificTypes
     testScientificTypes.hpp
     testScientificTypes.cpp
)
TARGET_LINK_LIBRARIES(testALBAZScientificTypes
     Qt${QT_VERSION_MAJOR}::Test
     Qt${QT_VERSION_MAJOR}::Core
)
ADD_TEST(testALBAZScientificTypes testALBAZScientificTypes)
SET_TARGET_PROPERTIES(testALBAZScientificTypes PROPERTIES FOLDER "plugins/ALBAZCrescent/src/test")
