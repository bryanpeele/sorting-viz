#include <stdio.h>
#include <iostream>
#include <vector>

#include "sort_utils.h"
#include "image_utils.h"
#include "bubble.h"


std::ostream &operator<<(std::ostream &os, const std::vector<int> &vector) {
    std::string delim = "";
    for( auto i=0; i < vector.size(); i++) {
        os << delim << vector[i];
        delim = ",";
    }
    return os;
}


int main(){
    int length = 10;

    std::vector<int> initial_sequence = generateRandomSequence(length);
    std::cout<<"Initial sequence: "<<initial_sequence<<std::endl;

    std::vector<int> initial_sequence_2 = generateRandomSequence(length);
    std::cout<<"Initial sequence: "<<initial_sequence_2<<std::endl;

    std::vector<int> initial_sequence_3 = generateRandomSequence(length);
    std::cout<<"Initial sequence: "<<initial_sequence_3<<std::endl;

    std::vector<std::vector<int>> image = {initial_sequence,
                                           initial_sequence_2,
                                           initial_sequence_3};

    std::cout<<"Image height: "<<image.size()<<std::endl;
    std::cout<<"Image width: "<<image[0].size()<<std::endl;
    convertVecToImage(image,"random.ppm");

    std::vector<int> test_sequence = generateOrderedSequence(length);
    std::cout<<"Test sequence: "<<test_sequence<<std::endl;

    bubbleSort bubble;
    bubble.swap(test_sequence,3);
    std::cout<<"Test sequence, swap 3<->4: "<<test_sequence<<std::endl;

    bubble.forwardPass(test_sequence);
    std::cout<<"Test sequence, forward pass: "<<test_sequence<<std::endl;

    std::cout<<std::endl;

    std::vector<int> random_sequence = generateRandomSequence(100);
    std::cout<<"Random sequence: "<<random_sequence<<std::endl;
    BubbleResults results = bubble.sort(random_sequence);
    std::cout<<"Sorted sequence: "<<random_sequence<<" after "<<results.total_swaps<<" swaps"<<std::endl;

    convertVecToImage(results.sort_trajectory,"bubble.ppm");
    //convert random.ppm -scale 500x random.png
    //eog random.png

    return 0;
}