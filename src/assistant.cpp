#include <iostream>
#include <fstream>
#include <cstdlib>
#include "speech_recognition.h"
#include "speech_synthesis.h"
#include "gpt4all_interface.h"

int main() {
    std::cout << "🎙️ Say something..." << std::endl;

    std::string user_input = recognize_speech();
    std::cout << "You: " << user_input << std::endl;

    std::string ai_response = get_gpt4all_response(user_input);
    std::cout << "Assistant: " << ai_response << std::endl;

    synthesize_speech(ai_response);

    return 0;
}