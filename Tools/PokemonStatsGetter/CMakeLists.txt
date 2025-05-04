cmake_minimum_required(VERSION 3.24.1)

project(PokemonStatGetter)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/PokemonGetter.cpp
)

target_link_libraries(${PROJECT_NAME}
    libcurl
    ssl
    crypto
    TinyXML_Boosted
)
