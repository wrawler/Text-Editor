#pragma once

#include <string>
#include "lib/nativefiledialog/src/include/nfd.hpp"
#include<iostream>
#include<fstream>

std::string openDialog(void);
std::string getOutput(std::string);
void saveDialog(void);
