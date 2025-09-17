import json
import os

# adjust these to your project
CC = "cc"
CFLAGS = ["-Wall", "-Werror", "-Wextra", "-Iinc"]

# list of all source files from your Makefile
SRC = [
    "main.c",
    "init/add_philo_to_table.c",
    "init/close_table.c",
    "init/data_check.c",
    "init/init_data.c",
    "init/init_forks.c",
    "init/init_philo.c",
    "init/syntax_check.c",
    "user_utils/ft_error.c",
    "user_utils/ft_usage.c",
    "user_utils/print_log.c",
    "prog_utils/cleanup_program.c",
    "prog_utils/ft_usleep.c",
    "prog_utils/ft_atoi.c",
    "prog_utils/get_time.c",
    "debug/print_philo.c",
    "debug/print_timelog.c",
    "routine/philo_routine.c",
    "routine/thread_init.c",
    "routine/thread_join.c",
    "routine/ober_routine.c",
    "routine/monitor_routine.c",
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

