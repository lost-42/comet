#!/usr/bin/env python3
"""Find the next undone LeetCode problem from the pre-sorted queue.

Reads problem_queue.txt (sorted by rating ascending), determines the highest
rating among already-solved problems, and picks the first undone problem
whose rating is >= that threshold.  This way the user always moves forward
in difficulty instead of going back to globally-lowest undone problems.

Usage:
    python3 find_next.py              # prints JSON for next undone problem
    python3 find_next.py --all-done   # exit 0 only if all problems are done

Exit codes:
    0 - found next problem
    1 - all done
"""

import glob
import json
import os
import re
import sys

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
QUEUE_FILE = os.path.join(SCRIPT_DIR, "problem_queue.txt")


def get_done_ids(cwd: str) -> set[int]:
    """Extract problem IDs from *.cpp files in cwd."""
    done = set()
    for path in glob.glob(os.path.join(cwd, "[0-9]*.cpp")):
        basename = os.path.basename(path)
        m = re.match(r"(\d+)", basename)
        if m:
            done.add(int(m.group(1)))
    return done


def compute_threshold(queue_lines: list[str], done: set[int]) -> float:
    """Return the highest rating among already-solved problems.

    Falls back to 0.0 when no solved problem appears in the queue.
    """
    max_rating = 0.0
    for line in queue_lines[1:]:
        parts = line.strip().split("\t")
        if len(parts) < 7:
            continue
        pid = int(parts[1])
        if pid in done:
            max_rating = max(max_rating, float(parts[0]))
    return max_rating


def main():
    cwd = os.getcwd()

    if not os.path.exists(QUEUE_FILE):
        print("Error: problem_queue.txt not found. Run prepare_queue.py first.", file=sys.stderr)
        sys.exit(1)

    done = get_done_ids(cwd)

    with open(QUEUE_FILE, "r", encoding="utf-8") as f:
        lines = f.readlines()

    min_rating = compute_threshold(lines, done)

    # Scan sorted queue.  Pick the first undone problem whose rating is
    # at least the threshold.
    for line in lines[1:]:
        line = line.strip()
        if not line:
            continue
        parts = line.split("\t")
        if len(parts) < 7:
            continue
        pid = int(parts[1])
        rating = float(parts[0])
        if pid not in done and rating >= min_rating:
            result = {
                "id": pid,
                "title": parts[2],
                "title_zh": parts[3],
                "title_slug": parts[4],
                "rating": rating,
                "contest_slug": parts[5],
                "problem_index": parts[6],
            }
            json.dump(result, sys.stdout, ensure_ascii=False)
            sys.stdout.write("\n")
            sys.exit(0)

    # --all-done flag: exit 0 instead of 1
    if "--all-done" in sys.argv:
        sys.exit(0)

    sys.exit(1)


if __name__ == "__main__":
    main()
