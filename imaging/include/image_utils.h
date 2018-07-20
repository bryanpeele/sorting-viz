#pragma once

#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <set>


void convertVecToImage(std::vector<std::vector<int>> vector_image,
                       std::string filename);

void convertVecToImageRedStreaks(std::vector<std::vector<int>> vector_image,
                                 std::string filename);

void convertVecToImageBlueStreaks(std::vector<std::vector<int>> vector_image,
                                  std::string filename,
                                  int color_threshold);