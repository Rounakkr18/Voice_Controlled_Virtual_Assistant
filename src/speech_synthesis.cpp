#include "speech_synthesis.h"
#include <iostream>
#include <cstdlib>

void synthesize_speech(std::string text) {
    std::string command = "C:\\Python313\\python.exe D:/Voice_Controlled_Virtual_Assistant/python/text_to_speech.py \"" + text + "\"";

    std::system(command.c_str());

    // Ensure Windows Media Player gets enough time to load
    #ifdef _WIN32
        std::system("powershell -Command \"Start-Sleep -Seconds 1\" && start wmplayer audio/output.mp3");
    #else
        std::system("sleep 1 && mpg123 audio/output.mp3");
    #endif

}
