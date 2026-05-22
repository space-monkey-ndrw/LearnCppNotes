# Automatically find all .cpp files inside this specific subfolder
file(GLOB SOURCES "*.cpp")

# Build the HelloWorld executable target
add_executable(HelloWorld ${SOURCES})