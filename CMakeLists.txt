cmake_minimum_required(VERSION 3.5)

project(RMGateway)

set(CMAKE_CXX_STANDARD 11)
set(ENABLE_JSON ON)

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
