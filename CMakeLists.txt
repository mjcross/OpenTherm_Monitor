# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.2.0)
set(toolchainVersion 14_2_Rel1)
set(picotoolVersion 2.2.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(OpenTherm_Monitor C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Source files in the project directory
set(SOURCE_FILES
    main.c
    OT_frame.c)

# Add executable. Default name is the project name, version 0.1

add_executable(OpenTherm_Monitor OpenTherm_Monitor.c OT_frame.c)

pico_set_program_name(OpenTherm_Monitor "OpenTherm_Monitor")
pico_set_program_version(OpenTherm_Monitor "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(OpenTherm_Monitor 1)
pico_enable_stdio_usb(OpenTherm_Monitor 0)

# Add the standard library to the build
target_link_libraries(OpenTherm_Monitor
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(OpenTherm_Monitor PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

#------------------------------------
# generate our user-defined libraries
#------------------------------------
add_subdirectory(OT_rx_library)
add_subdirectory(OT_tx_library)

# Add any user requested libraries
target_link_libraries(OpenTherm_Monitor 
        hardware_pio
		OT_rx_library
        OT_tx_library
        )

pico_add_extra_outputs(OpenTherm_Monitor)

