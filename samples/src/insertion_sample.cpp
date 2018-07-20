#include <stdio.h>
#include <iostream>
#include <vector>

#include "sort_utils.h"
#include "image_utils.h"
#include "cocktail.h"

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vector) {
    std::string delim = "";
    for( auto i=0; i < vector.size(); i++) {
        os << delim << vector[i];
        delim = ",";
    }
    return os;
}


int main(){
    int length = 1000;

    CocktailSort cocktail;

    std::vector<int> random_sequence = generateRandomSequence(length);
    std::cout<<"Random sequence: "<<random_sequence<<std::endl;
    CocktailResults results = cocktail.sort(random_sequence);
    std::cout<<"Sorted sequence: "<<random_sequence<<" after "<<results.total_swaps<<" swaps"<<std::endl;

    convertVecToImage(results.sort_trajectory,"cocktail-simple-1000.ppm");
    //convert random.ppm -scale 500x random.png
    //convert bubble.ppm -resize 800x800\! bubble-100L.png
    //eog random.png

    return 0;
}