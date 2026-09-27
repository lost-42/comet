# AGENTS.md

This file provides guidance to pi (and other AGENTS.md-aware agents) when working with code in this repository.

## Build & Run

Each `X.cpp` file is self-contained (Solution class + main function). Build, run and clean up with:

```bash
scripts\lc.cmd <id>.cpp
```

This initializes the MSVC environment (`scripts/msvc-env.cmd` -> vcvars64), then runs `cl /std:c++latest /EHsc /utf-8 /Z7 /Od <id>.cpp utils.cpp` into a temporary exe, executes it, and deletes the exe/obj. `scripts/lc-build.cmd <id>.cpp` is compile-only and is used as the VSCode preLaunch task for debugging. (The old WSL script was `./lc.sh`.) If the problem uses `TreeNode`, also include `utils.h` and link `utils.cpp`.

In VSCode: task **lc: build & run current file** (`Ctrl+Shift+B` runs the build task, or bind the run task); **F5** builds and debugs the current file.

## Project structure

- `X.cpp` — LeetCode problem #X with a `class Solution` and a `main()` containing inline test cases (actual vs expected printed to stdout)
- `utils.h` / `utils.cpp` — shared helpers: `TreeNode` / `buildTree` / `deleteTree`, `printVector`, `printVector2D`, `printMap`, `printQueue`, `printPriorityQueue`, `intToBinaryString`, `binaryStringToInt`
- `lc.sh` — legacy POSIX build-and-run script (WSL); superseded by `scripts/lc.cmd`
- `scripts/lc.cmd` / `scripts/lc-build.cmd` — MSVC build-and-run / build-only
- `scripts/msvc-env.cmd` — initializes the MSVC x64 environment (vcvars64)
- `.clang-format` — Google-based style, 4-space indent, 80-col limit, C++23
- `.clangd` — (removed) IntelliSense is now the Microsoft C/C++ extension, configured via `.vscode/c_cpp_properties.json`

## Format

- `using namespace std;` after includes
- Solution methods match the LeetCode function signature from the problem page
- Test blocks in `main()` are wrapped in `{}` scopes and print both actual output and expected output
- Problem description lives as `// ` comment block at the top of the file, ending with the LeetCode URL

## Skills

Custom skills live in `.pi/skills/` (auto-discovered by pi; invoke with `/skill:name` or by matching the task):

- **`add-test`** — Adds a `main()` function with test cases parsed from the `示例` sections in the file's header comment. Never modifies the Solution class.
- **`next-problem`** — Picks the next undone problem (rating ≥ highest solved rating), fetches problem content, scaffolds the `.cpp` file with header comment and Solution stub, then invokes `add-test`. Scripts live in `.pi/skills/next-problem/`: `prepare_queue.py` (builds queue from rating data), `find_next.py` (selects next problem), `fetch_problem.py` (fetches problem content from LeetCode CN API).
- **`hint`** — Guides the user through optimizing a LeetCode solution via Socratic questioning. Never writes code or gives direct answers; uses folded `<details>` blocks so the user can think before seeing each insight. Triggered when the user asks for analysis, optimization hints, or complexity improvement suggestions.
- **`review`** — Manages the review list in `.pi/skills/review/review.md`: `add_to_review.py` appends a problem; `pick_for_review.py` randomly picks an unreviewed problem added ≥ 20 days ago and clears its Solution body to re-solve.

Python scripts are run with `uv run --no-project python <script>.py` (this machine has no working system `python3`).

## Settings

All pi configuration must go to the Git-tracked `.pi/settings.json` and repo-tracked resources under `.pi/`, never to machine-local or gitignored files. This repository is used by a single developer across multiple devices, so every setting, skill, and script must travel with the repo.

## Behavior

- **Never proactively suggest solutions.** Do not offer ideas, hints, algorithms, or implementation approaches for LeetCode problems unless the user explicitly asks. When the user opens a problem file or describes a problem, only assist with mechanics (build, test, format, skill invocation) — never with solving the problem itself.
