#include "image_utils.h"

void convertVecToImage(std::vector<std::vector<int>> vector_image,
                       std::string filename){
    int height = vector_image.size();
    int width = vector_image[0].size();
    std::ofstream image_file;

    image_file.open(filename);


    if (!image_file.is_open()) { std::cout<<"FUCK"; }

    image_file << "P3\n";// P6 filetype
    image_file << width << " " << height << std::endl;
    image_file << "255" << std::endl;


    for (int h = 0; h < height; ++h){
        for (int w = 0; w < width; ++w){
            auto pixel_value = static_cast<int>(static_cast<float>(vector_image[h][w])/static_cast<float>(width)*255.f);
            image_file << pixel_value << " " << pixel_value << " "
                       << pixel_value << "    ";
        }
        image_file << std::endl;
    }
    image_file.close();
};

void convertVecToImageRedStreaks(std::vector<std::vector<int>> vector_image,
                                 std::string filename){
    int height = vector_image.size();
    int width = vector_image[0].size();
    std::ofstream image_file;

    image_file.open(filename);


    if (!image_file.is_open()) { std::cout<<"FUCK"; }

    image_file << "P3\n";// P6 filetype
    image_file << width << " " << height << std::endl;
    image_file << "255" << std::endl;
    //fprintf(image_file,"%d %d\n",width,height); // dimensions
    //fprintf(image_file,"255\n");                // Max pixel

    char pixels[] = {};
    for (int h = 0; h < height; ++h){
        for (int w = 0; w < width; ++w){
            int pixel_value = static_cast<int>(static_cast<float>(vector_image[h][w])/static_cast<float>(width)*255.f);
            if (vector_image[h][w] %5 == 0){
                image_file << "255 0 0    ";
            } else {
                image_file << pixel_value << " " << pixel_value << " "
                           << pixel_value << "    ";
            }
        }
        image_file << std::endl;
    }
    image_file.close();
};

void convertVecToImageBlueStreaks(std::vector<std::vector<int>> vector_image,
                                  std::string filename,
                                  int color_threshold){

    int height = vector_image.size();
    int width = vector_image[0].size();
    std::ofstream image_file;

    std::set<int> streaks;
    int first_row = 0;
    for (int position = 0; position < width; ++position){
        int value = vector_image[first_row][position];
        if (position > (value+color_threshold)){
            streaks.insert(value);
        }
    }

    image_file.open(filename);


    if (!image_file.is_open()) { std::cout<<"FUCK"; }

    image_file << "P3\n";// P6 filetype
    image_file << width << " " << height << std::endl;
    image_file << "255" << std::endl;
    //fprintf(image_file,"%d %d\n",width,height); // dimensions
    //fprintf(image_file,"255\n");                // Max pixel

    for (int h = 0; h < height; ++h){
        for (int w = 0; w < width; ++w){
            auto pixel_value = static_cast<int>(static_cast<float>(vector_image[h][w])/static_cast<float>(width)*255.f);
            auto it = streaks.find(vector_image[h][w]);
            if (it != streaks.end()){
                image_file << "0 0 255    ";
            } else {
                image_file << pixel_value << " " << pixel_value << " " << pixel_value
                           << "    ";
            }
        }
        image_file << std::endl;
    }
    image_file.close();
};