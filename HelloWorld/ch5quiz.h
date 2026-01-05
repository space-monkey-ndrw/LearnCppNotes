#pragma once
#ifndef CH5QUIZ_H
#define CH5QUIZ_H
#include <string>
#include <string_view>
std::string getName(int personNum);
int getAge(std::string_view name);
void printOlder(std::string_view name1, int age1, std::string_view name2, int age2);
void ch5quiz();
void questionTwo();
void q2fixed();
#endif