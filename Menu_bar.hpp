#pragma once

#include<map>
#include<string>

// File Menu Default states
std::map<std::string, bool> requiredWindows = {
    {"newWindow",false},
    {"openDialog",false},
    {"saveDialog",false},
    {"exitWindow",false},
    {"notesWindow",false}
};
