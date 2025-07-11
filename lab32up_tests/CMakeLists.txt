cmake_minimum_required(VERSION 3.16)

project(lab32up_tests VERSION 0.1 LANGUAGES CXX)

# �������� �������������� ��������� Qt ������
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# �������� C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ����� Qt (���� � Qt6, � Qt5)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)

# �������� ����� �������
set(PROJECT_SOURCES
    mainwindow.h
    mainwindow.cpp
    car.h
    car.cpp
    tests.cpp
)

# ������� ����������� ���� � �������
add_executable(lab32up_tests
    ${PROJECT_SOURCES}
)

# ������� ���������� Qt
target_link_libraries(lab32up_tests
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Test
)

# ��������� ����� � CTest
enable_testing()
add_test(NAME Lab32UpTests COMMAND lab32up_tests)

# ������������� ����� ��� �������� ������ (�����������)
set_target_properties(lab32up_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
