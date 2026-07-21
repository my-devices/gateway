cmake_minimum_required(VERSION 3.12)

project(RMGateway)

set(CMAKE_CXX_STANDARD 11)
set(ENABLE_JSON ON)

option(SKIP_PAGECOMPILER "Skip PageCompiler invocation" OFF)

if (NOT SKIP_PAGECOMPILER)
	# Locate the cpspc executable (same as before).
	find_program(PAGECOMPILER
		NAMES cpspc
		DOC "Path to the POCO C++ Libraries Server Page Compiler (cpspc) code generator"
	)
	if(NOT PAGECOMPILER)
		message(FATAL_ERROR
			"cpspc code generator not found. Make sure it is installed and its "
			"prefix is included in CMAKE_PREFIX_PATH.")
	endif()

	find_program(FILE2PAGE
		NAMES f2cpsp
		DOC "Path to the File2Page (f2cpsp) code generator"
	)
	if(NOT FILE2PAGE)
		message(FATAL_ERROR
			"f2cpsp code generator not found. Make sure it is installed and its "
			"prefix is included in CMAKE_PREFIX_PATH.")
	endif()

	message(STATUS "Using cpspc: ${PAGECOMPILER} and f2cpsp: ${FILE2PAGE}")

	file(GLOB RESOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/res/*")

	file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated)

	# Create one custom command per resource file, declaring exactly which
	# files it produces and what it depends on. This is what lets the
	# build system skip regeneration when nothing has changed.
	foreach(res_file ${RESOURCE_FILES})
		get_filename_component(res_name_we "${res_file}" NAME_WE)

		set(gen_cpsp "${CMAKE_CURRENT_BINARY_DIR}/generated/${res_name_we}.cpsp")
		set(gen_header "${CMAKE_CURRENT_SOURCE_DIR}/src/${res_name_we}.h")
		set(gen_source "${CMAKE_CURRENT_SOURCE_DIR}/src/${res_name_we}.cpp")

		add_custom_command(
			OUTPUT ${gen_cpsp}
			COMMAND ${FILE2PAGE} ${res_file} -o ${gen_cpsp} --namespace MyDevices::Gateway
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src"
			DEPENDS ${res_file} ${FILE2PAGE}
			COMMENT "Generating ${res_name_we}.cpsp from ${res_file}"
			VERBATIM
		)

		add_custom_command(
			OUTPUT ${gen_header} ${gen_source}
			COMMAND ${PAGECOMPILER} ${gen_cpsp} -o ${CMAKE_CURRENT_SOURCE_DIR}/src
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src"
			DEPENDS ${gen_cpsp} ${PAGECOMPILER}
			COMMENT "Generating ${res_name_we}.h and ${res_name_we}.cpp from ${res_name_we}.cpsp"
			VERBATIM
		)
	endforeach()

	file(GLOB CPSP_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpsp")
	file(GLOB INC_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/html/*.inc")

	set(CPSPC_GENERATED_SOURCES "")

	foreach(cpsp_file ${CPSP_FILES})
		get_filename_component(cpsp_name_we "${cpsp_file}" NAME_WE)

		set(gen_header "${CMAKE_CURRENT_SOURCE_DIR}/src/${cpsp_name_we}.h")
		set(gen_source "${CMAKE_CURRENT_SOURCE_DIR}/src/${cpsp_name_we}.cpp")

		add_custom_command(
			OUTPUT ${gen_header} ${gen_source}
			COMMAND ${PAGECOMPILER} ${cpsp_file}
			WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src"
			DEPENDS ${cpsp_file} ${PAGECOMPILER} ${INC_FILES}
			COMMENT "Generating ${cpsp_name_we}.h and ${cpsp_name_we}.cpp from ${cpsp_name_we}.cpsp"
			VERBATIM
		)

		list(APPEND CPSPC_GENERATED_SOURCES ${genHeader} ${genSource})
	endforeach()
endif()

if(WIN32)
	option(ENABLE_NETSSL_WIN "Enable NetSSL Windows" ON)
	option(ENABLE_NETSSL "Enable NetSSL (OpenSSL)" OFF)
else()
	option(ENABLE_NETSSL "Enable NetSSL (OpenSSL)" ON)
endif()

option(POCO_STATIC "Set to OFF|ON (default is OFF) to use POCO as STATIC library" ON)

if(MSVC)
	option(POCO_MT "Set to OFF|ON (default is OFF) to use POCO as /MT instead of /MD" ON)
	option(ENABLE_MSVC_MP "Set to OFF|ON (default is OFF) to control parallel build with MSVC" ON)
endif()

if(MSVC)
	if(POCO_MT)
		set(CompilerFlags
			CMAKE_CXX_FLAGS
			CMAKE_CXX_FLAGS_DEBUG
			CMAKE_CXX_FLAGS_RELEASE
			CMAKE_C_FLAGS
			CMAKE_C_FLAGS_DEBUG
			CMAKE_C_FLAGS_RELEASE
		)
		foreach(CompilerFlag ${CompilerFlags})
			string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
		endforeach()

		set(STATIC_POSTFIX "mt" CACHE STRING "Set static library postfix" FORCE)
    else(POCO_MT)
			set(STATIC_POSTFIX "md" CACHE STRING "Set static library postfix" FORCE)
	endif(POCO_MT)

	if (ENABLE_MSVC_MP)
		add_definitions(/MP)
	endif()
else(MSVC)
	# Other compilers then MSVC don't have a static STATIC_POSTFIX at the moment
	set(STATIC_POSTFIX "" CACHE STRING "Set static library postfix" FORCE)
	set(CMAKE_C_FLAGS_DEBUG   "${CMAKE_C_FLAGS_DEBUG}   -D_DEBUG")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_DEBUG")
endif(MSVC)

if(ENABLE_NETSSL_WIN)
  find_package(Poco REQUIRED COMPONENTS WebTunnel NetSSLWin Net JSON Util Foundation)
elseif(ENABLE_NETSSL)
  find_package(Poco REQUIRED COMPONENTS WebTunnel NetSSL Crypto Net JSON Util Foundation)
else()
  find_package(Poco REQUIRED COMPONENTS WebTunnel Net JSON Util Foundation)
endif()

if(POCO_STATIC)
    set(LIB_MODE_DEFINITIONS -DPOCO_STATIC -DPOCO_NO_AUTOMATIC_LIBS)
    set(LIB_MODE STATIC)
    message(STATUS "Building with static libraries")
else(POCO_STATIC)
    set(LIB_MODE SHARED)
    set(LIB_MODE_DEFINITIONS -DPOCO_NO_AUTOMATIC_LIBS)
    message(STATUS "Building with dynamic libraries")
endif(POCO_STATIC)

# Sources
file(GLOB SRCS "src/*.cpp")

add_executable(rmgateway ${SRCS})

if(ENABLE_NETSSL_WIN)
	target_compile_definitions(rmgateway PUBLIC WEBTUNNEL_ENABLE_TLS=1)
	target_link_libraries(rmgateway Poco::NetSSLWin)
else()
  find_package(OpenSSL)
  if(OPENSSL_FOUND)
    if(ENABLE_NETSSL)
	    target_include_directories(rmgateway PUBLIC "${OPENSSL_INCLUDE_DIR}")
	    target_compile_definitions(rmgateway PUBLIC WEBTUNNEL_ENABLE_TLS=1)
	    target_link_libraries(rmgateway Poco::NetSSL Poco::Crypto ${OPENSSL_SSL_LIBRARY} ${OPENSSL_CRYPTO_LIBRARY})
    endif()
  endif()
endif()

if(UNIX AND NOT APPLE)
  target_link_libraries(rmgateway crypt)
endif()

target_link_libraries(rmgateway Poco::WebTunnel Poco::Net Poco::Util Poco::JSON Poco::Foundation)
