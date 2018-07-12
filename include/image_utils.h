#include <cstdlib>
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

void convertVecToImage(std::vector<std::vector<int>> vector_image, std::string filename){
    int height = vector_image.size();
    int width = vector_image[0].size();
    std::ofstream image_file;

    image_file.open(filename);


    if (!image_file.is_open()) { std::cout<<"FUCK"; }

    image_file << "P6\n";// P6 filetype
    image_file << width << " " << height << std::endl;
    image_file << "255" << std::endl;
    //fprintf(image_file,"%d %d\n",width,height); // dimensions
    //fprintf(image_file,"255\n");                // Max pixel

    char pixels[] = {};
    for (int h = 0; h < height; ++h){
        for (int w = 0; w < width; ++w){
            int pixel_value = static_cast<int>(static_cast<float>(vector_image[h][w])/static_cast<float>(width)*255.f);
            image_file << pixel_value << " " << pixel_value << " " << pixel_value << "    ";
        }
        image_file << std::endl;
    }
    image_file.close();
};