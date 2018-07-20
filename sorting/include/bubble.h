#pragma once

struct BubbleResults{
    int total_swaps;
    std::vector<std::vector<int>> sort_trajectory;
};


class bubbleSort {
public:
    void swap(std::vector<int> &initial_sequence, int index_left){
        //Test that index_left and index_right exist
        int temp = initial_sequence[index_left];
        initial_sequence[index_left] = initial_sequence[index_left + 1];
        initial_sequence[index_left + 1] = temp;
    };

    int forwardPass(std::vector<int> &initial_sequence){
        int index = 0;
        int num_swaps = 0;
        while (index < (initial_sequence.size()-1)){
            if (initial_sequence[index]>initial_sequence[index+1]){
                swap(initial_sequence, index);
                //sort_trajectory.push_back(initial_sequence);
                ++num_swaps;
            }
            sort_trajectory.push_back(initial_sequence);
            ++index;
        }
        return num_swaps;
    };

    BubbleResults sort(std::vector<int> &initial_sequence){
        int local_swaps = 999999;
        int total_swaps = 0;
        while (local_swaps>0){
            local_swaps = forwardPass(initial_sequence);
            total_swaps += local_swaps;
        }
        BubbleResults results;
        results.total_swaps = total_swaps;
        results.sort_trajectory = sort_trajectory;
        return results;
    }

private:
    std::vector<std::vector<int>> sort_trajectory;
    bool is_sorted_ = false;

};