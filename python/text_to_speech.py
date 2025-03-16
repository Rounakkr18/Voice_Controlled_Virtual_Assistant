from gtts import gTTS
import sys
import os
import subprocess

# Ensure the audio folder exists
if not os.path.exists("audio"):
    os.makedirs("audio")

text = sys.argv[1]
tts = gTTS(text)
tts.save("audio/output.mp3")

# Play using Windows Media Player
subprocess.call(['start', 'wmplayer', os.path.abspath("audio/output.mp3")], shell=True)
