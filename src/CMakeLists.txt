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
