# My project defintions

add_library(LinearAlgebra SHARED 
    TestLib.cxx
    )

# Test my vector implementation
set(VECTOR_TEST_EXE vector_test)
set(ALL_TESTS ${ALL_TESTS} ${VECTOR_TEST_EXE})
add_executable(${VECTOR_TEST_EXE} EXCLUDE_FROM_ALL TestVector.cxx)
target_link_libraries(${VECTOR_TEST_EXE}
  LinearAlgebra
  libgmock
  libgtest
  )
add_test(TestVector ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${VECTOR_TEST_EXE})

# Test my matrix implementation
set(MATRIX_TEST_EXE matrix_test)
set(ALL_TESTS ${ALL_TESTS} ${MATRIX_TEST_EXE})
add_executable(${MATRIX_TEST_EXE} EXCLUDE_FROM_ALL TestMatrix.cxx)
target_link_libraries(${MATRIX_TEST_EXE}
  LinearAlgebra
  libgmock
  libgtest
  )
add_test(TestMatrix ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${MATRIX_TEST_EXE})

# adds target to build and run all tests
# call with "make check"
# Warning this will download and install gtest and gmock.
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}
                      DEPENDS ${ALL_TESTS})

FOREACH (TEST_FILE ${ALL_TESTS})
  install(TARGETS ${TEST_FILE} DESTINATION bin OPTIONAL)
ENDFOREACH()
