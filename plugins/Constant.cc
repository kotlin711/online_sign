//
// Created by crying711 on 2022/11/19.
//
#include <atomic>
#include <map>
#include "iostream"
std::atomic<int> num=5000;
std::map<std::string, int> map;
time_t now = time(0);
char* start_time = ctime(&now);




