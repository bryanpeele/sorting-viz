#include "insertion.h"

SortResults InsertionSort::sort(std::vector<int> &initial_sequence){
    int total_swaps = 0;
    int value, sort_index;
    for (int i = 1; i < initial_sequence.size(); ++i){
        value = initial_sequence[i];
        sort_index = i-1;
        while(sort_index >= 0 && initial_sequence[sort_index] > value){
            initial_sequence[sort_index+1] = initial_sequence[sort_index];
            --sort_index;
            ++total_swaps;
            sort_trajectory.push_back(initial_sequence);
        }
        initial_sequence[sort_index+1] = value;
        ++total_swaps;
        sort_trajectory.push_back(initial_sequence);
    }

    SortResults results;
    results.total_swaps = total_swaps;
    results.sort_trajectory = sort_trajectory;
    return results;
}