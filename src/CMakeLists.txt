# src cmake

include_directories(${PROJECT_SOURCE_DIR}/include)

set(PIKAXE_LIB_SOURCES 
    pik_mem.c
)

add_library(Pikaxe SHARED "${PIKAXE_LIB_SOURCES}")

add_library(PikaxeS STATIC "${PIKAXE_LIB_SOURCES}")