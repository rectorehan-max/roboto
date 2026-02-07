import os
import subprocess
import sys

CXX = "g++"
STD = "-std=c++17"

ROOT = os.path.dirname(os.path.abspath(__file__))

GAME_SRC = os.path.join(ROOT, "game", "src")
GAME_INCLUDE = os.path.join(ROOT, "game", "include")

RAYLIB_INCLUDE = os.path.join(ROOT, "external", "raylib", "include")
RAYLIB_LIB = os.path.join(ROOT, "external", "raylib", "lib")

BIN_DIR = os.path.join(ROOT, "bin")
OUTPUT = os.path.join(BIN_DIR, "main.exe")

os.makedirs(BIN_DIR, exist_ok=True)

cpp_files = []

for root, _, files in os.walk(GAME_SRC):
    for file in files:
        if file.endswith(".cpp"):
            cpp_files.append(os.path.join(root, file))

if not cpp_files:
    print("No cpp files found")
    sys.exit(1)
    
command = [
    CXX,
    STD,
    *cpp_files,
    
    f"-I{GAME_INCLUDE}",
    f"-I{RAYLIB_INCLUDE}",
    
    f"-L{RAYLIB_LIB}",
    "-lraylib",
    
    "-lgdi32",
    "-lwinmm",
    "-lopengl32",
    
    "-o",
    OUTPUT
]

print("Compiling project...")

result = subprocess.run(command)

if result.returncode == 0:
    print("Compiled Successfully!")
else:
    print("Compilation Failed")
