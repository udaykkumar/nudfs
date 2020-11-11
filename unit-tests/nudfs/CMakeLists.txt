# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)

file(GLOB UT_SOURCES_NUD_COMMON     "nud-common/*.cpp"  )
file(GLOB UT_SOURCES_NUD_CSL        "nud-csl/*.cpp"     )
file(GLOB UT_SOURCES_NUD_DEV        "nud-dev/*.cpp"     )
file(GLOB UT_SOURCES_NUD_FS         "nud-fs/*.cpp"      )
file(GLOB UT_SOURCES_NUD_UTILS      "nud-utils/*.cpp"   )


add_executable( "nudfs-unittest" 
                "suite-runner.cpp"
                ${UT_SOURCES_NUD_COMMON} ${TEST_SOURCES_NUD_COMMON}
                ${UT_SOURCES_NUD_CSL}
                ${UT_SOURCES_NUD_DEV}
                ${UT_SOURCES_NUD_FS}
                ${UT_SOURCES_NUD_UTILS} )

target_link_libraries( "nudfs-unittest"  ${Boost_LIBRARIES}  )