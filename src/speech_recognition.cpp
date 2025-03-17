#include <fstream>
#include "speech_recognition.h"
#include <iostream>
#include <cstdlib>

std::string recognize_speech() {
    std::cout << "🎤 Running speech recognition...\n";
    
    int ret = std::system("C:\\Python313\\python.exe D:/Voice_Controlled_Virtual_Assistant/python/recognize_speech.py");

    if (ret != 0) {
        std::cerr << "❌ Error: Failed to execute Python script." << std::endl;
        return "";
    }

    std::ifstream file("audio/input.txt");
    if (!file) {  
        std::cerr << "❌ Error: Could not open audio/input.txt!" << std::endl;
        return "";
    }

    std::string text;
    std::getline(file, text);
    file.close();

    if (text.empty() || text == "No speech detected") {
        std::cerr << "⚠️ No valid speech detected." << std::endl;
        return "No speech detected";
    }

    return text;
}
