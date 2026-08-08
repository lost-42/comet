# AGENTS.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build & Run

Each `X.cpp` file is self-contained (Solution class + main function). Build and run with:

```bash
./lc.sh <id>.cpp
```

This runs `clang++ -std=c++23 -stdlib=libc++ -g -O0 <id>.cpp utils.cpp -o <id>` then executes the binary and cleans it up. If the problem uses `TreeNode`, also include `utils.h` and link `utils.cpp`.

## Project structure

- `X.cpp` — LeetCode problem #X with a `class Solution` and a `main()` containing inline test cases (actual vs expected printed to stdout)
- `utils.h` / `utils.cpp` — shared helpers: `TreeNode` / `buildTree` / `deleteTree`, `printVector`, `printVector2D`, `printMap`, `printQueue`, `printPriorityQueue`, `intToBinaryString`, `binaryStringToInt`
- `lc.sh` — build-and-run script
- `.clang-format` — Google-based style, 4-space indent, 80-col limit, C++23
- `.clangd` — LSP config with `-std=c++23 -stdlib=libc++`

## Format

- `using namespace std;` after includes
- Solution methods match the LeetCode function signature from the problem page
- Test blocks in `main()` are wrapped in `{}` scopes and print both actual output and expected output
- Problem description lives as `// ` comment block at the top of the file, ending with the LeetCode URL

## Skills

Three custom skills automate problem workflow:

- **`add-test`** — Adds a `main()` function with test cases parsed from the `示例` sections in the file's header comment. Never modifies the Solution class.
- **`next-problem`** — Picks the next undone problem (rating ≥ highest solved rating), fetches problem content, scaffolds the `.cpp` file with header comment and Solution stub, then invokes `add-test`. Scripts live in `.claude/skills/next-problem/`: `prepare_queue.py` (builds queue from rating data), `find_next.py` (selects next problem), `fetch_problem.py` (fetches problem content from LeetCode CN API).
- **`hint`** — Guides the user through optimizing a LeetCode solution via Socratic questioning. Never writes code or gives direct answers; uses folded `<details>` blocks so the user can think before seeing each insight. Triggered when the user asks for analysis, optimization hints, or complexity improvement suggestions.

## Behavior

- **Never proactively suggest solutions.** Do not offer ideas, hints, algorithms, or implementation approaches for LeetCode problems unless the user explicitly asks. When the user opens a problem file or describes a problem, only assist with mechanics (build, test, format, skill invocation) — never with solving the problem itself.
