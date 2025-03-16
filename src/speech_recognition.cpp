#include <fstream>
#include "speech_recognition.h"
#include <iostream>
#include <cstdlib>

std::string recognize_speech() {
    std::system("\"C:\\Python313\\python.exe\" \"D:\\Voice_Controlled_Virtual_Assistant\\python\\recognize_speech.py\"");

    std::ifstream file("audio/input.txt");
    if (!file) {  
        std::cerr << "❌ Error: Could not open audio/input.txt!" << std::endl;
        return "";
    }

    std::string text;
    std::getline(file, text);
    file.close();

    return text.empty() ? "No speech detected" : text;
}
