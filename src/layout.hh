#pragma once
#include <vector>
#include <iostream>
#include <assert.h>
#include <iomanip>
class Layout
{
    public:
        Layout(int n);
        void dump();
//        void swap(int a, int b);
    private:
        std::vector<int> layout_;
        int size_;
};
