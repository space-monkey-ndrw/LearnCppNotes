# Automatically find all .cpp files inside this specific subfolder
file(GLOB SOURCES "*.cpp")

# Build the MultiplyByTwo executable target
add_executable(MultiplyByTwo ${SOURCES})