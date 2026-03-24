add_executable(calculator
    src/main.cpp
    src/menu/Menu.cpp
    src/menu/Mascotte.cpp
    src/prestige/PrestigeManager.cpp
)

target_include_directories(calculator PRIVATE src/)