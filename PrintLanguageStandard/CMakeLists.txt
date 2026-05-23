# Automatically find all .cpp files inside this specific subfolder
file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")

# Build the PrintLanguageStandard executable target
add_executable(PrintLanguageStandard ${SOURCES})