

add_executable(test1 test1.cxx)
target_link_libraries(test1 Boost::serialization)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test1
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
  PERMISSIONS
  OWNER_READ  OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )


add_executable(test1a test1a.cxx)
target_link_libraries(test1a Boost::serialization)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test1a
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
  PERMISSIONS
  OWNER_READ  OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )
add_executable(test1b test1b.cxx)
target_link_libraries(test1b Boost::serialization)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test1b
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
  PERMISSIONS
  OWNER_READ  OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )

add_executable(test1c test1c.cxx)
target_link_libraries(test1c Boost::serialization)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test1c
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
  PERMISSIONS
  OWNER_READ  OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )

add_executable(test1d test1d.cxx)
target_link_libraries(test1d Boost::serialization)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test1d
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
  PERMISSIONS
  OWNER_READ  OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )

add_executable(test1e test1e.cxx)
target_link_libraries(test1e Boost::serialization)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test1e
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
  PERMISSIONS
  OWNER_READ  OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )