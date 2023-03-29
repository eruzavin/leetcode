TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    cpp/easy/1.two_sum.cpp \
    cpp/easy/13.Roman_to_integer.cpp \
    cpp/easy/9.palindrome_number.cpp \
    cpp/medium/3.longest_substr_without_repeating_chars.cpp \
    cpp/main.cpp

include(cpp)

DISTFILES += \
    README.md \
    cpp/medium/3.longest_substr_without_repeating_chars.cpp
