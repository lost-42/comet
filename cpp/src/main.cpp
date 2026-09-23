// main.cpp - doctest entry point for the cpp11 learning environment.
//
// Every test case self-registers via TEST_CASE, so there is no manual
// registry / run_xxx aggregation any more. Adding a NEW test file only
// requires adding it to target_sources() in CMakeLists.txt.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
