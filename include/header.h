//
// Created by Matthieu Deroir on 23/03/2022.
//

#ifndef SIMIAMSVSMAAWOX_HEADER_H
#define SIMIAMSVSMAAWOX_HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>


using namespace std;

void print(string str);

int dmg_to_player(vector<vector<int>> map);

vector<vector<int>> push_row(vector<vector<int>> vec);

vector<vector<int>> spawner(vector<vector<int>> vec, int round);


#endif //SIMIAMSVSMAAWOX_HEADER_H
