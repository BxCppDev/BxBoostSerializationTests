
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(lib1 SHARED
  lib1/archives_list.hpp
  lib1/archives_instantiation.hpp
  lib1/base.hpp
  lib1/base.cpp
  lib1/base-serial.hpp
  lib1/class1.hpp
  lib1/class1.cpp
  lib1/class1-serial.hpp
  lib1/class2.hpp
  lib1/class2.cpp
  lib1/class2-serial.hpp
  lib1/class3.hpp
  lib1/class3.cpp
  lib1/class3-serial.hpp
  lib1/the_serializable.cpp
  )
target_link_libraries(lib1 Boost::serialization)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/liblib1${CMAKE_SHARED_LIBRARY_SUFFIX}
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/
  PERMISSIONS
  OWNER_READ OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )

add_executable(test2 test2.cxx)
target_link_libraries(test2 lib1)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test2
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
  PERMISSIONS
  OWNER_READ  OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )

add_executable(test2b test2b.cxx
  class4.hpp
  class4.cpp
  class4-serial.hpp
  )
target_link_libraries(test2b lib1)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test2b
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
  PERMISSIONS
  OWNER_READ  OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )

