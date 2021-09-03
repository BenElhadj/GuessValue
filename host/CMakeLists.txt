# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.
add_custom_command(
  OUTPUT GuessValue_u.h GuessValue_u.c GuessValue_args.h
  DEPENDS ${CMAKE_SOURCE_DIR}/GuessValue.edl
  COMMAND
    openenclave::oeedger8r --untrusted ${CMAKE_SOURCE_DIR}/GuessValue.edl
    --search-path ${OE_INCLUDEDIR} --search-path
    ${OE_INCLUDEDIR}/openenclave/edl/sgx)

add_executable(GuessValue_host host.c
                               ${CMAKE_CURRENT_BINARY_DIR}/GuessValue_u.c)

if (WIN32)
  copy_oedebugrt_target(GuessValue_host_oedebugrt)
  add_dependencies(GuessValue_host GuessValue_host_oedebugrt)
endif ()

target_include_directories(
  GuessValue_host PRIVATE # Needed for the generated file GuessValue_u.h
                          ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(GuessValue_host openenclave::oehost)
