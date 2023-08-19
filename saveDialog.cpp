#include "FileDialog.hpp"

void saveDialog()
{
    NFD::Guard nfdGuard;

    // auto-freeing memory
    NFD::UniquePath outPath;
    std::string filePath;

    nfdfilteritem_t filterItem[2] = {{"Source code", "c,cpp,cc"}, {"Headers", "h,hpp"}};

    // show the dialog
    nfdresult_t result = NFD::SaveDialog(outPath, filterItem, 2);

    if (result == NFD_OKAY) {filePath = outPath.get();} 
    else if (result == NFD_CANCEL) {std::cout << "User pressed cancel." << std::endl;} 
    else {std::cout << "Error: " << NFD::GetError() << std::endl;}
};