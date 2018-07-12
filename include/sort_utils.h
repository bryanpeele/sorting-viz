#include <cstdlib>
#include <vector>

std::vector<int> generateRandomSequence(int length){
    std::vector<int> ordered_sequence;
    for (int i = 0; i< length; ++i){
        ordered_sequence.push_back(i);
    }

    std::vector<int> random_sequence;

    while(ordered_sequence.size() > 0){
        int index = rand()%ordered_sequence.size();
        random_sequence.push_back(ordered_sequence[index]);
        ordered_sequence.erase(ordered_sequence.begin()+index);
    }

    return random_sequence;
};