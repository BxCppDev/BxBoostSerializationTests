

add_executable(test1 test1.cxx)
target_link_libraries(test1 Boost::serialization)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test1
  DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/
  PERMISSIONS
  OWNER_READ  OWNER_EXECUTE
  GROUP_READ GROUP_EXECUTE
  WORLD_READ WORLD_EXECUTE
  )