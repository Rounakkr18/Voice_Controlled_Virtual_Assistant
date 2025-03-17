#include <fstream>
#include "gpt4all_interface.h"
#include <iostream>
#include <cstdlib>

std::string sanitize_input(const std::string& input) {
    std::string sanitized = input;
    std::string special_chars = "&|><^\"";

    for (char c : special_chars) {
        size_t pos = 0;
        while ((pos = sanitized.find(c, pos)) != std::string::npos) {
            sanitized.insert(pos, "\\");
            pos += 2;
        }
    }

    return sanitized;
}

std::string get_gpt4all_response(std::string user_input) {
    user_input = sanitize_input(user_input);  // Escape special characters

    std::string command = "cmd /c \"C:\\Python313\\python.exe \"D:\\Voice_Controlled_Virtual_Assistant\\python\\ass_gpt4all.py\" \"" + user_input + "\" > output.txt\"";

    int status = std::system(command.c_str());
    if (status != 0) {
        std::cerr << "Error: Failed to execute Python script." << std::endl;
        return "Error: Unable to get response.";
    }

    std::ifstream file("output.txt");
    if (!file) {
        std::cerr << "Error: Failed to open output.txt." << std::endl;
        return "Error: No response generated.";
    }

    std::string response;
    std::getline(file, response);
    file.close();

    return response;
}
