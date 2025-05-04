cmake_minimum_required(VERSION 3.24.1)

project(PkmnLike)

include_directories(${PROJECT_SOURCE_DIR} Includes)

include_directories(${PROJECT_SOURCE_DIR}/Submodules/TinyXML_Boosted/Include)
include_directories(${PROJECT_SOURCE_DIR}/Submodules/TinyXML_Boosted/Include/TinyXML_Boosted)
add_library(TinyXML_Boosted
    ${PROJECT_SOURCE_DIR}/Submodules/TinyXML_Boosted/Sources/tinystr.cpp
    ${PROJECT_SOURCE_DIR}/Submodules/TinyXML_Boosted/Sources/tinyxml.cpp
    ${PROJECT_SOURCE_DIR}/Submodules/TinyXML_Boosted/Sources/tinyxmlerror.cpp
    ${PROJECT_SOURCE_DIR}/Submodules/TinyXML_Boosted/Sources/tinyxmlparser.cpp
    ${PROJECT_SOURCE_DIR}/Submodules/TinyXML_Boosted/Sources/XMLFileLoader.cpp
)

add_executable(${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/Sources/PokemonDefinition.cpp
    ${PROJECT_SOURCE_DIR}/Sources/PokemonFightHelper.cpp
    ${PROJECT_SOURCE_DIR}/Sources/PokemonTypes.cpp
    ${PROJECT_SOURCE_DIR}/Sources/main.cpp
)

target_link_libraries(${PROJECT_NAME} TinyXML_Boosted)






add_subdirectory(Tools/PokemonStatsGetter)