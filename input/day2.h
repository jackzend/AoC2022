#ifndef DAY2_H
#define DAY2_H

#include <string_view>

namespace AoC2022
{
constexpr std::string_view day2_input =
    "C X\nC Y\nC X\nB X\nB Z\nA Z\nC Y\nC Z\nB Z\nC X\nB Y\nC Y\nC Y\nA Y\nC Y\nC Y\nC Z\nC X\nB "
    "Z\nC Y\nA Y\nA Y\nC Z\nB Y\nA Y\nC Z\nC Y\nA Y\nA Y\nB Y\nC Y\nC Z\nC Y\nB X\nB Z\nC Y\nB "
    "Z\nA X\nC Z\nA Y\nB Y\nC Y\nC Y\nB Z\nB Y\nA Z\nC X\nC X\nC Y\nC X\nB Z\nA Y\nB X\nB Z\nC "
    "Z\nC X\nC X\nB Z\nA Y\nB Y\nC Y\nC Y\nA Y\nC X\nA Y\nB Z\nC Y\nC Y\nB Y\nC Y\nA Z\nA Z\nB "
    "X\nA Y\nC Y\nA Y\nC Y\nC Y\nC X\nC Y\nB Z\nC Y\nC Z\nC X\nB X\nC Y\nC Y\nC X\nC Z\nA Y\nC "
    "X\nB Z\nC X\nA Y\nB Y\nC Y\nA Y\nA Y\nA Y\nB Y\nC Y\nA Y\nA Y\nC Z\nC Y\nB Y\nC X\nC Y\nB "
    "Z\nB Z\nC X\nC Y\nC X\nC Y\nC Y\nA Y\nC Y\nC X\nC Y\nC Y\nB Y\nB Z\nA Y\nB Y\nA Y\nA Y\nC "
    "Y\nB X\nC Y\nC X\nA Y\nC X\nC X\nC Y\nC Y\nB Z\nC X\nA Y\nB Z\nC Z\nC X\nA Y\nB Z\nC Y\nB "
    "Y\nA Y\nA Y\nC Y\nB Y\nC Y\nC X\nC Y\nA Y\nC Y\nA Y\nB Y\nC X\nC Y\nC Y\nB Z\nB Z\nA Y\nC "
    "Y\nC Y\nC Y\nC Y\nA Y\nC X\nC Z\nC X\nA Y\nA Y\nA Y\nC Y\nB Z\nB Z\nC Y\nC Y\nB X\nC Y\nC "
    "Y\nB Z\nB X\nB Y\nC Y\nC Y\nC X\nB Y\nB Z\nB Z\nC Y\nC Y\nC X\nC X\nA Y\nC Y\nC Y\nB X\nB "
    "Z\nB X\nB Z\nB Y\nC X\nB X\nB Y\nB Z\nB Z\nB X\nB Z\nB Y\nC X\nC Y\nC X\nC X\nB Z\nC Y\nC "
    "Y\nC Y\nB Z\nC Y\nC X\nC Y\nC Y\nA Z\nC Y\nA Y\nC Y\nA Z\nA X\nC Y\nC Y\nC Y\nC Z\nB Z\nB "
    "Z\nC Y\nB Z\nB Z\nC X\nC Y\nA Y\nA Y\nC Y\nA Y\nC Y\nC Y\nB Y\nA Y\nC Y\nB Z\nA Y\nB Z\nC "
    "X\nC Y\nA Y\nB Z\nA Y\nC X\nC Y\nB Y\nC Y\nA Z\nB Z\nB X\nC Y\nA Y\nA Z\nC X\nA Y\nB Z\nA "
    "Y\nB Y\nC Y\nC Y\nB Z\nB Z\nC X\nB Z\nC X\nC Z\nC Y\nC X\nA Y\nC X\nA Y\nA Y\nB Z\nB Z\nB "
    "Z\nA Y\nA Y\nC Y\nA Y\nB Z\nC X\nC Y\nC Y\nC Y\nB Y\nA Y\nC Z\nC Y\nA Y\nA Y\nB Z\nC Y\nC "
    "Y\nC Y\nB Z\nC Y\nC Y\nA Y\nA Y\nC Y\nC X\nB Z\nB Z\nC X\nC X\nC Z\nA Y\nC Y\nA Y\nA Y\nC "
    "X\nA Z\nB Y\nA Y\nC X\nA Y\nC X\nC X\nA Y\nA Y\nC X\nB Y\nB Z\nC Y\nC Z\nC Y\nC Y\nB Z\nC "
    "Y\nA Y\nA X\nB Y\nC Y\nA Y\nC Y\nC Y\nC Y\nA Y\nC Y\nA Y\nC Y\nB Z\nA Y\nC X\nC Y\nA Y\nC "
    "Y\nA Y\nA Y\nA Y\nB Z\nC Y\nB Z\nA Y\nC Y\nA Y\nC Y\nC X\nB Z\nA Y\nC X\nB Z\nB Y\nC Y\nC "
    "Z\nC Y\nB Y\nB Y\nA Y\nA Y\nC X\nB Y\nA Y\nC Y\nB X\nC X\nA Y\nC Y\nA Y\nC Y\nB Z\nA Z\nB "
    "Z\nB Z\nA Z\nC Y\nC Y\nC X\nB Y\nC Y\nA Y\nC Y\nC Y\nB Y\nB Z\nC Y\nC X\nA Y\nC X\nC X\nC "
    "Y\nB Y\nC Y\nB Z\nC Y\nA Y\nA Y\nC Y\nC X\nC X\nC X\nC Y\nC X\nC Y\nC Y\nA Y\nC Y\nC X\nC "
    "Y\nC X\nC X\nC X\nA Y\nB Y\nC Y\nC Y\nC Y\nC Y\nC Y\nA Y\nA X\nB Z\nC X\nC Y\nC Y\nB Z\nA "
    "Y\nA Y\nB X\nB Z\nC Y\nC Y\nB Z\nA Y\nA Y\nA Y\nC Y\nC Y\nA Y\nA Y\nC Y\nC Y\nC X\nC X\nC "
    "X\nB Z\nC Z\nC X\nA Z\nC Y\nC X\nA Y\nB Y\nB Z\nC X\nC Y\nC Y\nC Z\nC Y\nC X\nA Z\nC Y\nA "
    "X\nB Y\nC Y\nC Y\nC Y\nC X\nB Y\nB Y\nC X\nB X\nA Y\nC Y\nC Y\nC Y\nB X\nC Y\nA Y\nC Y\nC "
    "Y\nB Z\nC X\nB X\nC Z\nC Y\nA Y\nB Y\nB Z\nC Z\nC X\nC X\nA Y\nA Y\nB Z\nA Y\nC X\nB Y\nC "
    "Y\nA Y\nB X\nA Y\nA Y\nC Z\nC Y\nC Z\nB Z\nA X\nC Y\nB Y\nC Y\nB Z\nB Y\nC Y\nA Y\nB Z\nB "
    "Z\nC X\nB Z\nC Y\nB Z\nB Z\nC Y\nC Y\nB Z\nC Z\nC Y\nB Z\nC Y\nB X\nA Y\nB Z\nA Y\nC Y\nA "
    "Y\nC Y\nC Y\nB Y\nB Z\nB Z\nC Y\nA Y\nB Z\nC X\nC Y\nC Y\nA Y\nC Y\nC Y\nC X\nA Y\nC Y\nC "
    "Y\nA Y\nC X\nA Y\nA Y\nA Y\nC Y\nC Y\nA Y\nB Z\nA Y\nB Y\nA Y\nA Y\nC Y\nC Y\nC Z\nA Y\nC "
    "Y\nB Z\nA Y\nC Y\nC Z\nC Y\nC Y\nB Z\nC Y\nC Y\nB Z\nB Y\nC Y\nA Y\nC X\nC Y\nC Z\nC Z\nC "
    "X\nC X\nC X\nC Z\nC Y\nB Z\nA Y\nB Z\nB Z\nA Y\nC Y\nC Y\nC Y\nB X\nC Y\nA Y\nA Z\nB Y\nB "
    "Y\nA Y\nB Z\nA Y\nB Y\nC Z\nC Y\nC Y\nC Y\nB Z\nB Z\nB Z\nC Y\nC Y\nA Y\nC X\nC X\nA Y\nC "
    "Y\nC Y\nC Y\nC Y\nC X\nC Y\nC Y\nC Y\nC X\nA Z\nB Y\nC Y\nA Y\nA Y\nB Z\nA Z\nC Y\nC Y\nC "
    "Y\nC X\nB X\nB Y\nC Y\nA Y\nA Z\nB X\nC Y\nC Y\nB Z\nA Y\nA Y\nB Z\nB Z\nC Y\nC Y\nC X\nB "
    "Y\nB Z\nC Y\nB Y\nC Y\nA Y\nC X\nC X\nB Z\nA Y\nC Y\nB Z\nC X\nC Y\nB Y\nB Z\nA Z\nB Y\nB "
    "Y\nC X\nC Y\nA Z\nC X\nC X\nA Y\nA Y\nC X\nA Y\nB Y\nB Z\nA Y\nB Z\nB X\nC Y\nC Y\nC X\nB "
    "Z\nA Y\nB Y\nA Y\nC Y\nC Z\nB Z\nC Y\nA Y\nC Y\nC Z\nA Z\nB Z\nB X\nC Y\nC Y\nB Y\nC X\nB "
    "Y\nB Z\nB Z\nB X\nB Y\nC X\nC Y\nC X\nC Y\nA Y\nA Y\nC Y\nA Y\nC Y\nC X\nC Y\nA Y\nB Z\nC "
    "X\nC Y\nB Z\nC Y\nC Y\nB Y\nB Z\nA X\nC Y\nB Y\nB Y\nB Z\nC Y\nB Z\nA Y\nC Y\nB Y\nC Y\nA "
    "Y\nC Y\nB Z\nC Y\nA Y\nA Y\nC Y\nA Y\nC Y\nA Y\nA Y\nB Z\nC X\nC Y\nB Z\nC Y\nA X\nA Z\nC "
    "Y\nC X\nC X\nC Y\nC Y\nB Z\nA Z\nA Y\nC Y\nB Z\nA Y\nA Y\nC Y\nB Z\nA Y\nC X\nA Y\nA Y\nC "
    "X\nB Z\nB X\nA X\nA Y\nB Y\nA X\nB X\nC X\nC Y\nA Y\nC Y\nA Y\nA Y\nC X\nB Y\nC X\nB Y\nC "
    "Y\nC Y\nA Y\nB Z\nA Z\nB Y\nC X\nC Y\nC Y\nB Z\nC Z\nA Y\nA Y\nA Z\nC Y\nA Y\nB Z\nC Y\nC "
    "Y\nB Y\nA Y\nA Y\nC Y\nC X\nC X\nB Y\nB Z\nC Y\nB Y\nB Z\nC Y\nA Y\nB Z\nA Y\nA Y\nA Z\nC "
    "X\nB Z\nC Y\nB Z\nA Y\nC X\nC Y\nC Y\nB X\nB Z\nA Y\nA Y\nA Y\nA Y\nA Y\nC Y\nA Y\nA Y\nC "
    "X\nC Y\nC Z\nB Z\nA Z\nC Z\nA Y\nB Z\nB Y\nA Y\nC Y\nB Z\nA Y\nC Y\nC Y\nA Y\nC Y\nB Z\nB "
    "Y\nB Z\nC Y\nC Y\nC Y\nA Z\nC X\nB X\nB Z\nC Z\nC Y\nC Y\nC Y\nC X\nA Y\nC Y\nA Y\nA Y\nB "
    "Z\nA Y\nC Y\nC Y\nA Y\nC Y\nA Z\nB X\nA Y\nC Y\nA Y\nA Z\nA Y\nA Y\nB Z\nB Y\nB Z\nC Y\nB "
    "Z\nC X\nA Y\nC Y\nA Y\nA Y\nA Y\nB Z\nB Z\nC Y\nB Z\nB Y\nC X\nA Y\nC Y\nA Y\nB Z\nC X\nB "
    "Y\nC Y\nB Z\nC Y\nA Y\nC Y\nC Y\nB Y\nB Z\nC Y\nB Z\nB Y\nC Y\nC X\nA Z\nC Z\nC Y\nC Y\nA "
    "Y\nA Y\nC X\nC Y\nC Y\nC Y\nC X\nB Z\nC X\nC Y\nA Y\nA Y\nB Z\nA Y\nA Y\nC Y\nA Y\nB Z\nC "
    "X\nC Y\nC Y\nC Y\nC Y\nC X\nB Z\nA Y\nB Y\nC Y\nC X\nB Z\nC Y\nA Y\nA Y\nB Z\nC Y\nA Y\nC "
    "Z\nC X\nB Z\nC Y\nA Z\nB Z\nA Y\nA Y\nC Y\nB Z\nB Z\nA Y\nC Y\nB Y\nC Y\nA Y\nA Y\nB Y\nB "
    "X\nB Z\nC Y\nA Y\nC Y\nA Y\nA Y\nB Z\nB Y\nA Y\nA Y\nA Y\nC Y\nB Y\nC Y\nA Y\nC X\nC Y\nC "
    "Y\nB Z\nB Z\nC Y\nC Y\nA Y\nB X\nC X\nA Y\nC Y\nC Y\nC Y\nA Y\nC X\nB Z\nA Y\nC Z\nB Y\nB "
    "Y\nC Z\nA Y\nC Z\nC Y\nC X\nB Y\nA Y\nC X\nC X\nC Y\nC X\nC X\nB Z\nC Y\nB Y\nA Y\nB Y\nA "
    "Y\nB Z\nC X\nC Y\nC X\nC Z\nC X\nB Z\nC X\nC Y\nC Y\nC Y\nB Z\nA Y\nC Y\nC Y\nC Y\nB Z\nA "
    "Y\nC X\nC Y\nC Y\nC Y\nC X\nA Z\nC Y\nC Y\nC X\nB X\nB Z\nA Y\nB Z\nC Y\nB Y\nB Z\nA Y\nB "
    "Z\nC Y\nA Y\nA X\nC X\nC X\nC Y\nA Y\nB X\nC Y\nB X\nB Z\nC X\nA Y\nB X\nC X\nA Y\nC Y\nC "
    "Y\nC Y\nA Z\nC Y\nA Y\nB Z\nB Z\nA Z\nC Y\nA Y\nB Z\nC Z\nC X\nC X\nC X\nA Y\nA X\nC Y\nA "
    "Y\nB Y\nC Y\nC X\nC Y\nC Y\nA Y\nB Z\nC Y\nB Z\nA Y\nC X\nC Y\nB Z\nC Y\nC Y\nB Y\nA Y\nA "
    "Y\nA Z\nC Y\nB Z\nB Y\nB Z\nB Y\nA Y\nC Y\nC Y\nC X\nC Y\nC Y\nB Z\nC Y\nC Y\nC X\nB Y\nB "
    "Z\nC Y\nC Y\nA Y\nC Z\nC Y\nB Z\nA Y\nA X\nA Y\nC X\nC Y\nC Y\nB Z\nA Y\nB X\nC Z\nC Z\nC "
    "X\nC Y\nB Z\nC Z\nB Z\nC Y\nA Y\nC Y\nA Y\nB X\nC X\nC Y\nB Z\nC Y\nB Y\nB X\nB X\nB Z\nC "
    "Y\nC Y\nB Y\nB Z\nC Y\nA Y\nB Z\nC Y\nB Z\nC Y\nB Z\nC Y\nA Y\nA Y\nC Y\nC Y\nB Y\nB Z\nC "
    "Y\nB Z\nC X\nB Z\nC Y\nB X\nC X\nB Z\nA Y\nC X\nB Z\nC Y\nA Y\nB Z\nA X\nB Z\nB Z\nB Z\nC "
    "Y\nC Y\nC Y\nC Y\nA Y\nA Y\nB Z\nB X\nC X\nC Y\nB Y\nA Y\nA Y\nB Z\nC Y\nA Y\nA Y\nC Y\nC "
    "X\nC Y\nC X\nC Y\nC Y\nC Y\nB Z\nC Y\nC X\nB Y\nC Y\nC Y\nC Y\nA Z\nC X\nC Y\nA Y\nC Y\nB "
    "Z\nB Y\nC Y\nA Y\nA Y\nC Y\nC Y\nC X\nA Y\nC Y\nA Z\nA Y\nB Z\nA Y\nC X\nC Y\nC Y\nB X\nB "
    "Z\nC X\nB X\nC Z\nC X\nB Z\nB Z\nC Y\nC X\nB Z\nB Z\nB Z\nC Y\nC Y\nA Y\nC Y\nB Y\nB X\nC "
    "Y\nC Y\nC Y\nB X\nC X\nB X\nC Y\nA Y\nC Y\nC X\nC Y\nC Y\nB X\nB Z\nA Z\nB Z\nA Y\nB Z\nC "
    "X\nB Z\nC Y\nC Y\nC Z\nA Y\nC Y\nC Y\nA Z\nB Y\nC Y\nA X\nA Y\nB Y\nC Y\nB Z\nC Y\nC X\nC "
    "Y\nB Z\nA Y\nC X\nC Y\nC X\nC Y\nC Y\nC Z\nA Y\nC Y\nB Z\nA Y\nC Z\nC Y\nA Y\nC Y\nC Y\nC "
    "Y\nC Y\nA Y\nC Y\nC Y\nC Y\nC Y\nB Z\nC X\nA Y\nA Y\nC Y\nB Y\nC Y\nC Y\nA Z\nC Y\nB Y\nC "
    "Y\nB Z\nC X\nA Y\nC Y\nC Y\nB Z\nC Y\nA Y\nA Y\nC Y\nB Z\nC Y\nA Y\nB Z\nC Y\nC Y\nB Z\nC "
    "X\nB Z\nB Z\nC Y\nC Y\nA Y\nC X\nA Y\nC Y\nB Z\nA Y\nB Z\nA Y\nC X\nC Y\nB Z\nB Y\nB Z\nA "
    "Y\nB Z\nC Y\nB Z\nC Y\nB Y\nA Y\nB Z\nB X\nB Z\nC Y\nB Z\nB Z\nB Z\nA Y\nA Y\nC Y\nB Z\nB "
    "Z\nC X\nB Z\nC Z\nA Y\nB Z\nB Z\nC Y\nB Z\nB Z\nC X\nC Z\nA Z\nC Y\nC Y\nB X\nC Z\nC Y\nA "
    "Y\nB Z\nC X\nB Z\nC Y\nC Y\nB Z\nB Z\nB Z\nC X\nC Y\nC X\nC X\nA Y\nB Z\nB Y\nC Y\nC Y\nB "
    "Z\nC Y\nC Y\nC Y\nC Y\nC Y\nB X\nA Y\nA Y\nB Y\nC Y\nB Y\nC Y\nB Y\nB Z\nC Y\nC Y\nC X\nB "
    "Y\nA Y\nB X\nB Z\nC X\nA X\nC Y\nA Y\nA Y\nC X\nB Y\nA Y\nB Z\nC X\nB Z\nC Z\nC X\nC Y\nC "
    "X\nC Y\nC Y\nC Y\nB Y\nC Z\nC X\nB Z\nC Y\nC X\nC X\nB Y\nC Y\nC Y\nC Z\nB Z\nC Y\nC Y\nB "
    "Y\nC Z\nC X\nB Z\nC Y\nC X\nC Y\nB Z\nC Y\nC Y\nA Y\nB Y\nC X\nC Y\nC Y\nC Y\nB Y\nB Y\nC "
    "Z\nB Z\nC Y\nB Z\nA Z\nC X\nB X\nC X\nA Y\nC Y\nA Z\nC X\nC Y\nA Y\nA Y\nB Y\nA Y\nC Y\nB "
    "Y\nC X\nC X\nC X\nC X\nC Y\nC Y\nA Y\nB Z\nC Y\nA Z\nC Y\nA Y\nB Z\nB Z\nC Y\nA Z\nC Y\nC "
    "Y\nC Y\nB Z\nC Y\nC Y\nA X\nA Y\nA Z\nC Y\nA Y\nB X\nA Y\nB Z\nB Y\nB Z\nB Y\nC X\nC X\nA "
    "Y\nB Z\nB Y\nC X\nB X\nB Y\nA Y\nC Y\nC Y\nC Y\nB Z\nC Y\nA Y\nB Z\nC X\nB Z\nB Z\nB X\nB "
    "Y\nC Y\nC Y\nC X\nB Z\nC Y\nC Y\nC Y\nA Y\nC Y\nB Z\nB Y\nC Y\nC X\nC X\nB X\nB Z\nA Z\nC "
    "X\nA Y\nB Y\nC Y\nA Y\nB Y\nC Y\nC Y\nC Z\nC Y\nC X\nA Y\nC Y\nC Y\nB Z\nC Y\nC Y\nC Y\nC "
    "Y\nA Y\nB Z\nB Z\nC Y\nC Y\nC Y\nC Y\nC Y\nB Z\nC Y\nC Y\nC X\nA Y\nA Y\nC Y\nC X\nA Y\nB "
    "Z\nA Y\nC X\nC Y\nC Z\nC Y\nA Z\nA Y\nA Y\nB Y\nC Y\nC Y\nB Y\nC Y\nA Y\nC X\nB Z\nC X\nA "
    "Y\nB Z\nC X\nA Y\nC X\nC X\nA Z\nA Y\nB Y\nA Y\nB Y\nA Z\nC Y\nC Y\nC Y\nB Z\nC Y\nA Y\nB "
    "Z\nB Y\nC Y\nB Y\nC Z\nA Y\nB Y\nC Y\nB Y\nA Y\nB Z\nC Y\nC X\nC Y\nA Y\nA Z\nC Y\nB Z\nC "
    "Y\nB Y\nA Y\nC X\nA Z\nC Z\nC X\nA Y\nC X\nC X\nC Y\nC Z\nA Y\nA Y\nC Y\nA Y\nC Y\nB Z\nC "
    "X\nA X\nC X\nC Y\nC Y\nC Y\nC Y\nB Z\nB Z\nB Z\nC X\nC Y\nB Y\nC Y\nB Y\nC Z\nA X\nB Y\nC "
    "X\nB Y\nC X\nB Y\nC Y\nB Z\nC X\nA Y\nB Z\nC X\nA X\nC Y\nB Z\nB Z\nC X\nB Z\nB Z\nC X\nC "
    "Y\nC Z\nB Z\nC Y\nC Y\nC Y\nB X\nA Y\nB Y\nB Z\nB Z\nC X\nA Z\nC Y\nC Y\nA Y\nA X\nA Y\nC "
    "Y\nB Y\nC Y\nA Y\nC X\nC Y\nC Y\nC Y\nC Y\nC Y\nC Y\nC Y\nC Y\nC Y\nC Y\nB Z\nB Z\nA Y\nB "
    "Y\nC Y\nC Y\nC X\nB Z\nA Y\nC Y\nB Z\nC Y\nA Y\nC X\nB X\nC Z\nA Y\nC X\nB Y\nC X\nB Z\nA "
    "Y\nC Y\nC Y\nC Y\nB Z\nB Z\nA Z\nC Z\nA Y\nB Z\nC X\nC Y\nA Y\nC Y\nC Y\nC X\nB Z\nC Z\nC "
    "Y\nB Z\nA X\nB Y\nA Z\nB X\nC X\nA Y\nC Y\nB Z\nB Z\nC Y\nA Y\nB Z\nB Z\nA Y\nA Y\nB Z\nB "
    "Z\nA X\nB Z\nC Y\nC Z\nC Y\nC Y\nB Z\nC Y\nA Z\nA X\nC X\nB Y\nB Z\nC X\nB Z\nA X\nA Y\nA "
    "Y\nB X\nB Y\nB Z\nC X\nC X\nC X\nC Y\nC Y\nB X\nC Y\nC Y\nA Y\nC X\nA Y\nB Z\nA Y\nC Y\nB "
    "X\nC X\nC Y\nA Y\nC X\nC Y\nC Y\nB Z\nA Y\nA Y\nA Z\nC Y\nB Z\nA Z\nB X\nA Z\nC Y\nB X\nA "
    "Y\nC Y\nC Z\nA Z\nC X\nA Y\nB X\nC Y\nC Y\nC X\nC Z\nA Y\nA Y\nC Y\nB Z\nC Y\nC X\nB X\nA "
    "Y\nB Y\nB Z\nB Z\nC Y\nC Y\nA Y\nB Z\nB Z\nC Y\nC Z\nC Y\nC Y\nC X\nC X\nA Y\nB Z\nA Y\nB "
    "Z\nB Z\nC X\nB X\nC X\nC Y\nB X\nB Z\nC X\nC X\nC X\nB Z\nB Y\nB Z\nC Y\nC Y\nB Z\nB Y\nB "
    "Z\nC Y\nB Y\nA Y\nA Y\nB Y\nA Y\nB Z\nA Y\nC X\nA Y\nC Z\nB Y\nC Y\nC X\nC X\nC Y\nC X\nC "
    "Y\nA Y\nB Z\nC X\nC Y\nC Y\nC Y\nC Y\nC Y\nB Y\nA Y\nB Z\nC Y\nA Z\nC Y\nB Z\nC X\nC Z\nA "
    "Y\nB Z\nC X\nC Y\nB Z\nC Y\nA Y\nC Y\nC X\nC X\nC Y\nA Y\nB Y\nA X\nC Y\nC Y\nA Y\nC Y\nA "
    "X\nC Y\nB Y\nC X\nB Z\nB Z\nB Y\nC Y\nC Z\nC X\nB Z\nB Z\nB Y\nC Z\nA Y\nC Y\nC Y\nB Y\nC "
    "X\nA Y\nC Y\nC Y\nA Z\nA Y\nB Y\nC Y\nC Y\nC X\nB X\nC Y\nA Y\nB Z\nB Y\nA Y\nB Y\nC Y\nC "
    "X\nC Y\nC Y\nC X\nA Y\nB Z\nC X\nC Z\nB X\nC Y\nC X\nC Y\nC X\nC Y\nB Z\nA Y\nA Y\nB Z\nC "
    "Y\nC Y\nB Z\nC Y\nC X\nB Z\nC Y\nB Z\nC X\nC Y\nC X\nA Y\nC Y\nA X\nC Y\nC X\nA Y\nC Y\nA "
    "Y\nC Y\nA Y\nC X\nA Y\nA Y\nA Y\nB Y\nB Z\nC Y\nB Z\nA Y\nC Y\nC X\nB X\nC Y\nB Z\nB X\nB "
    "X\nB Y\nC Y\nC X\nC Y\nC X\nB Y\nB Z\nA Y\nB Y\nC Y\nC Z\nA Y\nC Y\nB Y\nA Y\nC X\nC Y\nA "
    "Y\nC Y\nA Z\nC Z\nC Y\nB Z\nC Y\nC Y\nB Y\nA Y\nC Z\nA X\nC Y\nB Z\nC Z\nB X\nC Y\nC X\nC "
    "X\nB Z\nB Z\nB X\nB Y\nC Y\nB Z\nB Z\nB Z\nA Y\nB Z\nC Y\nC Y\nA Y\nA X\nC Z\nA Y\nC Z\nC "
    "Y\nC X\nC Y\nC X\nB Z\nC Y\nA X\nB Z\nB Y\nC Y\nB Y\nC Y\nC Y\nA Y\nB Z\nB Y\nC Y\nC X\nC "
    "Y\nC Y\nB Z\nA Y\nB X\nC Y\nC Y\nC Y\nA Y\nC Y\nC Y\nC X\nC Z\nC X\nB Y\nA Y\nC Z\nB Z\nB "
    "Z\nA Y\nC Y\nC X\nB X\nC X\nB Z\nA Y\nC Y\nC Y\nB Z\nA Y\nB Y\nC X\nB Y\nB Z\nB Z\nB Z\nB "
    "X\nB Y\nB Z\nC X\nA Z\nA Y\nC Y\nA Y\nC Y\nC Y\nB Z\nB Z\nC X\nB X\nC Y\nA Z\nC Y\nC X\nC "
    "Y\nB Y\nC X\nB Z\nC Y\nC X\nB Z\nA Y\nA Y\nC Y\nA Y\nA Z\nC Y\nA Z\nA Y\nC Y\nC X\nB X\nC "
    "Y\nC Y\nC X\nA Y\nC X\nC Y\nB Z\nB X\nC Y\nA Y\nB X\nC Y\nB Y\nC X\nA Y\nB Z\nC Y\nC Y\nB "
    "Z\nA Y\nA Z\nC Y\nC Y\nC X\nA Y\nB Z\nB Z\nB Y\nB Z\nA Y\nC Y\nA Y\nB Y\nA Y\nC X\nC Y\nA "
    "Z\nA Z\nB Y\nA Y\nC Y\nA X\nC Y\nC Y\nB Z\nC Y\nC X\nC Y\nA Y\nC Y\nC Y\nC Y\nC Y\nA X\nC "
    "Y\nB Y\nC Y\nA Y\nC Y\nC X\nC X\nC Z\nB Z\nA Y\nB X\nC Y\nC Y\nC Y\nA Y\nB Z\nB Z\nC Y\nA "
    "Y\nB Z\nA Y\nC X\nC X\nA Y\nC Z\nC Y\nB Z\nB Z\nA Y\nA Y\nC Y\nA Y\nC Y\nA Y\nB Z\nC X\nC "
    "Y\nC Y\nA Y\nC Y\nA Y\nA Z\nB Y\nC Y\nC X\nA Y\nC X\nA X\nC Y\nC Y\nB Y\nC Y\nB Z\nA Y\nC "
    "X\nB Z\nA Y\nC X\nB Z\nA Y\nC Y\nB Z\nA Y\nB Z\nC X\nC Y\nC X\nC Y\nB Z\nC Y\nB Y\nC Z\nB "
    "Z\nC Y\nC Y\nA X\nC X\nA Y\nC Y\nB Z\nA Y\nA Z\nB Z\nC Y\nC Y\nA Y\nA Y\nA Y\nC X\nC Y\nA "
    "Z\nC Y\nC Z\nA Y\nA Y\nC Y\nC X\nC X\nC Z\nC Y\nC Z\nB Z\nA Y\nB Z\nB Z\nC X\nA Y\nB Y\nA "
    "Y\nA Z\nA Y\nC Y\nC Y\nC Z\nA Y\nC Y\nB Y\nC X\nC X\nB X\nC Y\nA Y\nC Z\nA Y\nB Z\nB Y\nC "
    "Y\nA Y\nA Y\nC Y\nC Y\nC Y\nC Y\nC Y\nC Y\nC Y\nA Y\nB Y\nA Y\nB Y\nB Y\nC X\nC X\nC Y\nA "
    "Y\nC Y\nC Y\nC Z\nC Y\nC Y\nB Y\nC Y\nB Y\nA Y\nC Y\nB Z\nC X\nC Y\nA Z\nA Z\n";
}
#endif
