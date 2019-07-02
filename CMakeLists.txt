cmake_minimum_required(VERSION 3.0)

project(RMGateway)

set(CMAKE_CXX_STANDARD 11)

find_package(Poco REQUIRED COMPONENTS WebTunnel NetSSL Crypto Net Util Foundation)
find_package(OpenSSL)

# Sources
file(GLOB SRCS "src/*.cpp")

add_executable(rmgateway ${SRCS})

if(OPENSSL_FOUND)
	target_include_directories(rmgateway PUBLIC "${OPENSSL_INCLUDE_DIR}")
	target_compile_definitions(rmgateway PUBLIC WEBTUNNEL_ENABLE_TLS=1)
	target_link_libraries(rmgateway Poco::NetSSL Poco::Crypto ${OPENSSL_SSL_LIBRARY} ${OPENSSL_CRYPTO_LIBRARY})
endif()

target_link_libraries(rmgateway Poco::WebTunnel Poco::Net Poco::Util Poco::Foundation)
