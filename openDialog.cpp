#include "FileDialog.hpp"

std::string openDialog(void)
{
    NFD::Guard nfdGuard;

    // auto-freeing memory
    NFD::UniquePath outPath;
    std::string filePath;

    nfdfilteritem_t filterItem[2] = {{"Source code", "c,cpp,cc"}, {"Headers", "h,hpp"}};

    // show the dialog
    nfdresult_t result = NFD::OpenDialog(outPath, filterItem, 2);

    if (result == NFD_OKAY) {filePath = outPath.get();} 
    else if (result == NFD_CANCEL) {std::cout << "User pressed cancel." << std::endl;} 
    else {std::cout << "Error: " << NFD::GetError() << std::endl;}

    return filePath;
}

std::string getOutput(std::string path) {
    std::ifstream inputfile(path);

    // seeking the end of file to get the size of the file
    inputfile.seekg(0, std::ios::end);
    std::streampos fileSize = inputfile.tellg();
    inputfile.seekg(0, std::ios::beg);

    //// Read the entire content into a string
    std::string fileContent(fileSize, '\0'); // Allocate space for the content
    inputfile.read(&fileContent[0], fileSize);

    inputfile.close();
    return fileContent;  // After this we have the content of the whole file in variable called 'fileContent'
}
