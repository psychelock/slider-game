#pragma once

#include <vector>
#include <iostream>
#include <assert.h>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>
#include <ncurses.h>
#include <cstring>
#include <csignal>
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define QUIT 113

class Layout
{
    public:
        Layout(int n);
        void dump();
        int win_cond();
        void my_swap(int a, int b);
        int move(char c);
        void move_up();
        void move_down();
        void move_left();
        void move_right();
    private:
        std::vector<int> layout_;
        int size_;
        int blank_;
};
