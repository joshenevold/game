add_library(weapons
  none.cpp
  cleaver.cpp
  hammer_big.cpp
  staff_green.cpp
  spear.cpp
  knife.cpp
  sword_red_gem.cpp
  spiked_club.cpp
  sword_rusty.cpp
  )

target_include_directories(weapons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(weapons PUBLIC engine events)
