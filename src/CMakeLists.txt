# My project defintions

add_library(LinearAlgebra SHARED 
  TestLib.cxx
)

if (BUILD_TESTS)
  # Test my vector implementation
  set(VECTOR_TEST_EXE vector_test)
  set(ALL_TESTS ${ALL_TESTS} ${VECTOR_TEST_EXE})
  add_executable(${VECTOR_TEST_EXE} VectorTest.cxx)
  target_link_libraries(${VECTOR_TEST_EXE}
    LinearAlgebra
    libgtest
    libgmock
  )
  add_test(VectorTest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${VECTOR_TEST_EXE})

  # Test my matrix implementation
  set(MATRIX_TEST_EXE matrix_test)
  set(ALL_TESTS ${ALL_TESTS} ${MATRIX_TEST_EXE})
  add_executable(${MATRIX_TEST_EXE} MatrixTest.cxx)
  target_link_libraries(${MATRIX_TEST_EXE}
    LinearAlgebra
    libgtest
    libgmock
  )
  add_test(MatrixTest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${MATRIX_TEST_EXE})

  FOREACH (TEST_FILE ${ALL_TESTS})
    install(TARGETS ${TEST_FILE} DESTINATION bin)
  ENDFOREACH()

  # adds target to build and run all tests
  # call with "make check"
  # Warning this will download and install gtest and gmock.
  add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}
                        DEPENDS ${ALL_TESTS})
endif(BUILD_TESTS)

#Documentation building
# Used from
# https://mementocodex.wordpress.com/2013/01/19/how-to-generate-code-documentation-with-doxygen-and-cmake-a-slightly-improved-approach/
option(BUILD_DOCS "Create and install the HTML based API documentation (requires Doxygen)" OFF)
IF(BUILD_DOCS)
  FIND_PACKAGE(Doxygen)
  IF(NOT DOXYGEN_FOUND)
    MESSAGE(FATAL_ERROR "Doxygen is needed to build the documentation.")
  ENDIF()


  SET( doxyfile_in          ${CMAKE_SOURCE_DIR}/src/Doxyfile.in         )
  SET( doxyfile             ${PROJECT_BINARY_DIR}/Doxyfile              )
  SET( doxy_html_index_file ${CMAKE_CURRENT_BINARY_DIR}/html/index.html )
  SET( doxy_output_root     ${PROJECT_BINARY_DIR}/docs            ) # Pasted into Doxyfile.in
  SET( doxy_input           "${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/include" ) # Pasted into Doxyfile.in
  SET( doxy_extra_files     ${CMAKE_CURRENT_SOURCE_DIR}/mainpage.dox    ) # Pasted into Doxyfile.in

  CONFIGURE_FILE( ${doxyfile_in} ${doxyfile} @ONLY )

  ADD_CUSTOM_COMMAND( OUTPUT ${doxy_html_index_file}
                      COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
                      # The following should be ${doxyfile} only but it
                      # will break the dependency.
                      # The optimal solution would be creating a
                      # custom_command for ${doxyfile} generation
                      # but I still have to figure out how...
                      MAIN_DEPENDENCY ${doxyfile} ${doxyfile_in}
                      #DEPENDS ${ALL_FILES} ${doxy_extra_files}
                      COMMENT "Generating HTML documentation")

  # TODO: I removed ALL from this, because it was still generating
  # each time make was run even with no changes. If I can figure out why
  # I should re add ALL
  ADD_CUSTOM_TARGET( docs DEPENDS ${doxy_html_index_file} )

# INSTALL( DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc )
ENDIF(BUILD_DOCS)
