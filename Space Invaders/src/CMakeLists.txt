SET(SRC Alien.cpp Bullet.cpp Bunker.cpp Entity.cpp EntityFactory.cpp Exception.cpp gameController.cpp GameFactory.cpp gameModel.cpp gameView.cpp Gun.cpp read.cpp utilities.cpp main.cpp)
ADD_EXECUTABLE(si ${SRC})
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(si ${SFML_LIBRARIES})
endif()

INSTALL(TARGETS si DESTINATION ${PROJECT_SOURCE_DIR}/bin)