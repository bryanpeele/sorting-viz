#pragma once

#include <cstdlib>
#include <vector>

struct SortResults{
    int total_swaps;
    std::vector<std::vector<int>> sort_trajectory;
};

std::vector<int> generateOrderedSequence(int length);

std::vector<int> generateRandomSequence(int length);