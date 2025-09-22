import json
import os

# adjust these to your project
CC = "cc"
CFLAGS = ["-Wall", "-Werror", "-Wextra", "-Iinc"]

# list of all source files from your Makefile
SRC = [
    "main.c",
    "check_syntax.c",
    "init_structs.c",
    "utils.c",
    ]

compile_commands = []
project_dir = os.getcwd()

for src in SRC:
    obj = "obj/" + src.replace(".c", ".o")
    command = f"{CC} {' '.join(CFLAGS)} -c {src} -o {obj}"
    compile_commands.append({
        "directory": project_dir,
        "command": command,
        "file": src
    })

with open("compile_commands.json", "w") as f:
    json.dump(compile_commands, f, indent=2)

print("Generated compile_commands.json")

