#pragma once
#include <vector>
#include "sort_utils.h"


class InsertionSort {
public:
    SortResults sort(std::vector<int> &initial_sequence);

private:
    std::vector<std::vector<int>> sort_trajectory;
};