# Install script for directory: /sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSecondariesAnalyser.so.0.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSecondariesAnalyser.so.0.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSecondariesAnalyser.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "/sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/Marlin/v01-05/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/lcio/v02-04-03/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/gear/v01-03-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CLHEP/2.1.3.1/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/ilcutil/v01-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/MarlinUtil/v01-07-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CED/v01-09-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/gsl/1.14/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/root/5.34.05/lib:/sps/hep/ilc/bilokin/Processors/Analysis/TestProcessor/build/lib:/sps/hep/ilc/bilokin/CALICE/calice_code/v04-08/install/lib")
    ENDIF()
  ENDFOREACH()
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES
    "/sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build/lib/libSecondariesAnalyser.so.0.1.0"
    "/sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build/lib/libSecondariesAnalyser.so.0.1"
    "/sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build/lib/libSecondariesAnalyser.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSecondariesAnalyser.so.0.1.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSecondariesAnalyser.so.0.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libSecondariesAnalyser.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/Marlin/v01-05/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/lcio/v02-04-03/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/gear/v01-03-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CLHEP/2.1.3.1/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/ilcutil/v01-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/MarlinUtil/v01-07-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CED/v01-09-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/gsl/1.14/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/root/5.34.05/lib:/sps/hep/ilc/bilokin/Processors/Analysis/TestProcessor/build/lib:/sps/hep/ilc/bilokin/CALICE/calice_code/v04-08/install/lib:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
           NEW_RPATH "/sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/Marlin/v01-05/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/lcio/v02-04-03/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/gear/v01-03-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CLHEP/2.1.3.1/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/ilcutil/v01-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/MarlinUtil/v01-07-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/CED/v01-09-01/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/gsl/1.14/lib:/sps/hep/ilc/bilokin/ilcsoft/v01-17-04/root/5.34.05/lib:/sps/hep/ilc/bilokin/Processors/Analysis/TestProcessor/build/lib:/sps/hep/ilc/bilokin/CALICE/calice_code/v04-08/install/lib")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/sps/hep/ilc/bilokin/Processors/Analysis/SecondariesAnalyser/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
