#pragma once
#include <vector>

struct CocktailResults{
    int total_swaps;
    std::vector<std::vector<int>> sort_trajectory;
};


class CocktailSort {
public:
    void swap(std::vector<int> &initial_sequence, int index_left);

    int forwardPass(std::vector<int> &initial_sequence);
    int backwardPass(std::vector<int> &initial_sequence);

    CocktailResults sort(std::vector<int> &initial_sequence);

private:
    std::vector<std::vector<int>> sort_trajectory;
    bool is_sorted_ = false;

};