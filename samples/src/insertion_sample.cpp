#include <stdio.h>
#include <iostream>
#include <vector>

#include "sort_utils.h"
#include "image_utils.h"
#include "insertion.h"

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vector) {
    std::string delim = "";
    for( auto i=0; i < vector.size(); i++) {
        os << delim << vector[i];
        delim = ",";
    }
    return os;
}


int main(){
    int length = 500;

    InsertionSort insertion;

    std::vector<int> random_sequence = generateRandomSequence(length);
    std::cout<<"Random sequence: "<<random_sequence<<std::endl;
    SortResults results = insertion.sort(random_sequence);
    std::cout<<"Sorted sequence: "<<random_sequence<<" after "<<results.total_swaps<<" swaps"<<std::endl;

    convertVecToImage(results.sort_trajectory,"insertion-simple-500.ppm");
    convertVecToImageRedStreaks(results.sort_trajectory,"insertion-red-500.ppm");
    convertVecToImageBlueStreaks(results.sort_trajectory,"insertion-blue-500.ppm",50);
    //convert random.ppm -scale 500x random.png
    //convert bubble.ppm -resize 800x800\! bubble-100L.png
    //eog random.png

    return 0;
}