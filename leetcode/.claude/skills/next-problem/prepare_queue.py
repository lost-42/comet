#!/usr/bin/env python3
"""Sort ratings.txt by rating (ascending) and write to problem_queue.txt.

Usage:
    python3 prepare_queue.py
"""

import os
import sys

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
RATINGS_FILE = os.path.join(SCRIPT_DIR, "ratings.txt")
QUEUE_FILE = os.path.join(SCRIPT_DIR, "problem_queue.txt")


def main():
    if not os.path.exists(RATINGS_FILE):
        print(f"Error: {RATINGS_FILE} not found", file=sys.stderr)
        sys.exit(1)

    with open(RATINGS_FILE, "r", encoding="utf-8") as f:
        lines = f.readlines()

    if not lines:
        print("Error: ratings.txt is empty", file=sys.stderr)
        sys.exit(1)

    header = lines[0]
    data = lines[1:]

    # Parse and sort by rating (column 0)
    parsed = []
    for line in data:
        line = line.strip()
        if not line:
            continue
        parts = line.split("\t")
        if len(parts) < 7:
            continue
        rating = float(parts[0])
        parsed.append((rating, line))

    parsed.sort(key=lambda x: x[0])

    with open(QUEUE_FILE, "w", encoding="utf-8") as f:
        f.write(header)
        for _, line in parsed:
            f.write(line + "\n")

    print(f"Sorted {len(parsed)} problems → {QUEUE_FILE}")


if __name__ == "__main__":
    main()
