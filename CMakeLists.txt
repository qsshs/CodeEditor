cmake_minimum_required(VERSION 3.6)
project(CodeEditor)

set(CMAKE_CXX_STANDARD 11)

option(BUILD_CODEEDIROT_EXAMPLE "CodeEditor Example building required" Off)

if (${BUILD_CODEEDIROT_EXAMPLE})
    message(STATUS "CodeEditor example will be built.")
    add_subdirectory(example)
endif()

set(RESOURCES_FILE
    resources/codeeditor_resources.qrc
)

set(INCLUDE_FILES
    include/QHighlightRule
    include/QHighlightBlockRule
    include/CodeEditor
    include/QCXXHighlighter
    include/QLineNumberArea
    include/QStyleSyntaxHighlighter
    include/QSyntaxStyle
    include/QGLSLCompleter
    include/QGLSLHighlighter
    include/QLanguage
    include/QXMLHighlighter
    include/QJSONHighlighter
    include/QLuaCompleter
    include/QLuaHighlighter
    include/QPythonHighlighter
    include/QFramedTextAttribute
    include/internal/QHighlightRule.hpp
    include/internal/QHighlightBlockRule.hpp
    include/internal/CodeEditor.hpp
    include/internal/QCXXHighlighter.hpp
    include/internal/QLineNumberArea.hpp
    include/internal/QStyleSyntaxHighlighter.hpp
    include/internal/QSyntaxStyle.hpp
    include/internal/QGLSLCompleter.hpp
    include/internal/QGLSLHighlighter.hpp
    include/internal/QLanguage.hpp
    include/internal/QXMLHighlighter.hpp
    include/internal/QJSONHighlighter.hpp
    include/internal/QLuaCompleter.hpp
    include/internal/QLuaHighlighter.hpp
    include/internal/QPythonCompleter.hpp
    include/internal/QPythonHighlighter.hpp
    include/internal/QFramedTextAttribute.hpp
)

set(SOURCE_FILES
    src/internal/CodeEditor.cpp
    src/internal/QLineNumberArea.cpp
    src/internal/QCXXHighlighter.cpp
    src/internal/QSyntaxStyle.cpp
    src/internal/QStyleSyntaxHighlighter.cpp
    src/internal/QGLSLCompleter.cpp
    src/internal/QGLSLHighlighter.cpp
    src/internal/QLanguage.cpp
    src/internal/QXMLHighlighter.cpp
    src/internal/QJSONHighlighter.cpp
    src/internal/QLuaCompleter.cpp
    src/internal/QLuaHighlighter.cpp
    src/internal/QPythonCompleter.cpp
    src/internal/QPythonHighlighter.cpp
    src/internal/QFramedTextAttribute.cpp
)

# Create code for QObjects
set(CMAKE_AUTOMOC On)

# Create code from resource files
set(CMAKE_AUTORCC ON)

# Find includes in corresponding build directories
find_package(Qt5Core    CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui     CONFIG REQUIRED)

add_library(CodeEditor STATIC
    ${RESOURCES_FILE}
    ${SOURCE_FILES}
    ${INCLUDE_FILES}
)

target_include_directories(CodeEditor PUBLIC
    include
)

if(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(CodeEditor
		PRIVATE
		-ansi
		-pedantic
		-Wall
		-Wextra
		-Weffc++
		-Woverloaded-virtual
		-Winit-self
		-Wunreachable-code
	)
endif(CMAKE_COMPILER_IS_GNUCXX)

target_link_libraries(CodeEditor
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
)
