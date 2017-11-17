set( LOGPORT_EXECUTABLE logport )

set(SOURCES
    main.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/logport)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS} ${RDKAFKA_INCLUDE_DIR})

#add_library(logport ${LOGPORT_LIBRARY_TYPE} ${SOURCES})
#set_target_properties(logport PROPERTIES VERSION ${LOGPORT_VERSION}
#                                          SOVERSION ${LOGPORT_VERSION})
#target_link_libraries(logport ${CPPKAFKA_LIBRARY})
#target_include_directories(logport PUBLIC ${PROJECT_SOURCE_DIR}/include)



add_executable( ${LOGPORT_EXECUTABLE} ${SOURCES} )
target_link_libraries( ${LOGPORT_EXECUTABLE} ${CPPKAFKA_LIBRARY})
target_include_directories( ${LOGPORT_EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/include)


install( 
    TARGETS logport
    RUNTIME DESTINATION bin
    COMPONENT dev
)