find_path(CPPKAFKA_ROOT_DIR
    NAMES include/libcppkafka/cppkafka.h
)

find_path(CPPKAFKA_INCLUDE_DIR
    NAMES cppkafka/producer.h
    HINTS ${CPPKAFKA_ROOT_DIR}/include
)

set(HINT_DIR ${CPPKAFKA_ROOT_DIR}/lib)

find_library(CPPKAFKA_LIBRARY
    NAMES cppkafka libcppkafka
    HINTS ${HINT_DIR}
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CPPKAFKA DEFAULT_MSG
    CPPKAFKA_LIBRARY
    CPPKAFKA_INCLUDE_DIR
)

if (HAVE_VALID_KAFKA_VERSION)
    message(STATUS "Found valid cppkafka version")
    mark_as_advanced(
        CPPKAFKA_ROOT_DIR
        CPPKAFKA_INCLUDE_DIR
        CPPKAFKA_LIBRARY
    )
else()
    message(FATAL_ERROR "Failed to find valid cppkafka version")
endif()
