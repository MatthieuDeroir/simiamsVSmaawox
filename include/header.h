//
// Created by Matthieu Deroir on 23/03/2022.
//

#ifndef SIMIAMSVSMAAWOX_HEADER_H
#define SIMIAMSVSMAAWOX_HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <ctime>
#include <typeinfo>
#include <map>

#define RESET       "\033[0m"
#define BLACK       "\033[30m"      /* Black */
#define RED         "\033[31m"      /* Red */
#define GREEN       "\033[32m"      /* Green */
#define YELLOW      "\033[33m"      /* Yellow */
#define BLUE        "\033[34m"      /* Blue */
#define MAGENTA     "\033[35m"      /* Magenta */
#define CYAN        "\033[36m"      /* Cyan */
#define WHITE       "\033[37m"      /* White */

#define BGBLACK     "\[\033[40m\]"       # Black
#define BGRED       "\033[41m"         /* Red */
#define BGGREEN     "\033[42m"       /* Green */
#define BGYELLOW    "\[\033[43m\]"      # Yellow
#define BGBLUE      "\[\033[44m\]"        # Blue
#define BGMAGENTA    "\033[45m"      /* Purple */
#define BGCYAN      "\[\033[46m\]"        # Cyan
#define BGWHITE     "\033[47m"       /* White */



using namespace std;

void print(string str);

void wait();

void color(char p, string color);

int count_vec(vector<vector<int> > vec);

void multiprint(string str, int nb);

#endif //SIMIAMSVSMAAWOX_HEADER_H

/*
 * 0 = black
 * 1 = red
 * 2 = green
 * 3 = yellow
 * 4 = dark blue
 * 5 = pink
 * 6 = light blue
 * 7 = white
 */
