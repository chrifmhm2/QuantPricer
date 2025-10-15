cmake_minimum_required(VERSION 3.15)
project(QuantPricer LANGUAGES CXX)

# === Configuration du compilateur ===
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

# === Dossiers d'inclusion ===
include_directories(
    ${PROJECT_SOURCE_DIR}                 # Inclut tous les headers du projet
    /usr/include/eigen3                   # <-- 🔹 Ajout ici pour Eigen
)

# === Recherche automatique des fichiers source ===
file(GLOB_RECURSE SRC_FILES
    "${PROJECT_SOURCE_DIR}/stochastic_models/*.cpp"
#    "${PROJECT_SOURCE_DIR}/stochastic_models/GeometricBrownianMotion.cpp"
#    "${PROJECT_SOURCE_DIR}/stochastic_models/Vasicek.cpp"
    "${PROJECT_SOURCE_DIR}/utils/*.cpp"
#    "${PROJECT_SOURCE_DIR}/options/*.cpp"
#    "${PROJECT_SOURCE_DIR}/pricing/*.cpp"
)

# === Création de la bibliothèque principale ===
add_library(QuantPricerLib ${SRC_FILES})

# === Création de l'exécutable principal ===
add_executable(QuantPricer main.cpp)
target_link_libraries(QuantPricer PRIVATE QuantPricerLib)

# === Messages d'information ===
message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Eigen directory: /usr/include/eigen3")
message(STATUS "Source files: ${SRC_FILES}")
