# Lazy Shell

**Lazy Shell** is a lightweight, educational Unix-like shell implemented in C. It provides a simple command-line interface, supports built-in commands, pipelines, I/O redirection, background job control, and basic signal handling.

---

## 📁 File Structure

```
Lazy_Shell/
├── include/
│   └── shell.h               # Public headers and declarations
├── src/
│   ├── command_executor.c    # Fork/exec logic for external commands & built-ins dispatcher
│   ├── job_controller.c      # Background/foreground job management and status checking
│   ├── parser.c              # Command-line parsing (splitting tokens & detecting pipelines)
│   ├── pipeline_executor.c   # Setting up pipes and executing two-stage pipelines
│   ├── redirection_handler.c # Handling `<` and `>` I/O redirection
│   ├── signal_handler.c      # Installing signal handlers for SIGINT/SIGTSTP
│   └── shell.c               # Main loop, prompt, and dispatch logic
├── tests/                    # (Optional) unit/integration test cases
├── Makefile                  # Build rules for compiling the shell
└── README.md                 # This file
```

---

## 🚀 Features

- **Built-in commands**:
  - `cd <dir>`: Change the current working directory
  - `help`     : Display a help message and list of built-ins
  - `exit`     : Exit the shell
- **External commands**: Fork + `execvp()` support for any system executable.
- **Pipelines**: Connect two commands via `|`, e.g. `ls -l | grep ".c"`.
- **I/O Redirection**:
  - `< input.txt`  : Redirect stdin from file
  - `> output.txt` : Redirect stdout to file (overwrite)
- **Job Control**:
  - Background jobs with `&`
  - `Ctrl-C` (SIGINT) kills the running child process without exiting the shell
  - `Ctrl-Z` (SIGTSTP) suspends the child process and adds it to the job list
- **Job Table**: Tracks up to 100 jobs, prints status messages when jobs stop or finish.
- **Signal Handling**: The shell itself ignores `SIGINT`/`SIGTSTP`; children reset to defaults.

---

## 🛠️ Build & Run

1. **Clone the repo**
   ```bash
   git clone https://github.com/yourusername/Lazy_Shell.git
   cd Lazy_Shell
   ```

2. **Compile**
   ```bash
   make
   ```
   This produces the `lazy_shell` executable in `bin/` (or the project root).

3. **Run**
   ```bash
   ./shell
   ```
   You should see the ASCII welcome banner and the prompt `Lazy shell $ `.

4. **Clean**
   ```bash
   make clean
   ```

---

## 🧪 Tests

If you add test cases in the `tests/` directory, you can automate running them via:
```bash
make test
```

*(No tests are included by default.)*

---

## ✍️ Contributing

Contributions, bug reports, and feature requests are welcome! Please open an issue or submit a pull request.

---

## 📄 License

This project is released under the MIT License. See [LICENSE](LICENSE) for details.

