cmake_minimum_required(VERSION 3.23)

project(learn LANGUAGES CXX)

# ---------------------------------------------------------------------------
# Toolchain / standard selection lives in CMakePresets.json, not here.
# This file must stay portable: no hardcoded compiler paths, no -stdlib=...
# ---------------------------------------------------------------------------

# Pick up every .cpp under src/ (recursive). CONFIGURE_DEPENDS makes the build
# system re-run the glob at build time, so adding a new test file does NOT
# require editing this list or re-configuring by hand.
file(GLOB_RECURSE LEARN_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(learn ${LEARN_SOURCES})

target_include_directories(learn PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/third_party"
)

target_compile_features(learn PRIVATE cxx_std_23)

# Sources may carry UTF-8 comments/strings; tell MSVC so it does not warn
# (C4819) or mangle them on non-UTF-8 code pages.
if(MSVC)
    target_compile_options(learn PRIVATE /utf-8)
endif()

# Stable output path so editor tasks can always find bin/learn.exe
set_target_properties(learn PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
