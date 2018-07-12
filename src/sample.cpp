#include <stdio.h>
#include <iostream>
#include <vector>

#include "../include/sort_utils.h"
#include "../include/image_utils.h"


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

    return 0;
}