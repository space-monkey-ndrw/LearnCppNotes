# Automatically find all .cpp files inside this specific subfolder
file(GLOB SOURCES "*.cpp")

# Build the PrintLanguageStandard executable target
add_executable(PrintLanguageStandard ${SOURCES})