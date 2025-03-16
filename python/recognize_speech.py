from vosk import Model, KaldiRecognizer
import pyaudio
import json
import os

# Load Vosk Model (Ensure "vosk-model" exists in your project directory)
MODEL_PATH = "vosk-model"
if not os.path.exists(MODEL_PATH):
    print("❌ Vosk model not found! Please place 'vosk-model' in the project directory.")
    exit(1)

model = Model(MODEL_PATH)
recognizer = KaldiRecognizer(model, 16000)

# Set up PyAudio for microphone input
p = pyaudio.PyAudio()
stream = p.open(format=pyaudio.paInt16, channels=1, rate=16000, input=True, frames_per_buffer=4096)
stream.start_stream()

print("🎤 Listening... Speak now!")

recognized_text = ""

while True:
    data = stream.read(4096, exception_on_overflow=False)
    
    if len(data) == 0:
        break  # No audio input
    
    if recognizer.AcceptWaveform(data):
        result = json.loads(recognizer.Result())
        recognized_text = result.get("text", "").strip()  # Extract recognized text safely
        
        if recognized_text:
            print(f"✅ Recognized: {recognized_text}")
            break  # Stop after first recognized sentence

# Save recognized text only if it's valid
if recognized_text:
    os.makedirs("audio", exist_ok=True)  # Ensure "audio/" exists
    with open("audio/input.txt", "w") as file:
        file.write(recognized_text)
else:
    print("❌ No speech detected.")

# Cleanup
stream.stop_stream()
stream.close()
p.terminate()
