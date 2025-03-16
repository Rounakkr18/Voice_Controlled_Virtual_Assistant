import sys
import os
from gpt4all import GPT4All

model_path = "D:/Voice_Controlled_Virtual_Assistant/models/Llama-3.2-3B-Instruct-Q4_0.gguf"

if not os.path.exists(model_path):
    print(f"Error: Model file not found at {model_path}")
    sys.exit(1)

llm = GPT4All(model_path)

if len(sys.argv) < 2:
    print("Error: No input provided. Please enter a message.")
    sys.exit(1)

user_input = sys.argv[1]
response = llm.generate(user_input)
print(response)
