# Automatically find all .cpp files inside this specific subfolder
file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")

# Build the HelloWorld executable target
add_executable(HelloWorld ${SOURCES})

# enable implicit type conversion warnings
target_compile_options(HelloWorld PRIVATE -Wconversion)