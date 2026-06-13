#!/usr/bin/env python3
"""Pick an eligible problem for review from review.md.

Filters: added >= 3 days ago, not yet reviewed (review_date == "-").
Randomly selects one, updates its review_date to today, prints JSON.

Usage:
    python3 pick_for_review.py

Exit codes:
    0 - found eligible problem (JSON to stdout)
    1 - no eligible problems
"""

import json
import os
import random
import re
import sys
from datetime import date, timedelta

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REVIEW_FILE = os.path.join(SCRIPT_DIR, "review.md")

MIN_AGE_DAYS = 20


def parse_review_file() -> list[dict]:
    """Parse review.md into a list of row dicts."""
    if not os.path.exists(REVIEW_FILE):
        return []

    rows = []
    with open(REVIEW_FILE, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            m = re.match(
                r"^\|\s*(\d+)\s*\|\s*(.+?)\s*\|\s*(\S+)\s*\|\s*(\S+)\s*\|$", line
            )
            if not m:
                continue
            rows.append(
                {
                    "id": int(m.group(1)),
                    "title": m.group(2).strip(),
                    "added_date": m.group(3),
                    "review_date": m.group(4),
                }
            )
    return rows


def main():
    rows = parse_review_file()

    if not rows:
        print("暂无需要复习的题目（复习列表为空）。", file=sys.stderr)
        sys.exit(1)

    today = date.today()
    cutoff = today - timedelta(days=MIN_AGE_DAYS)

    eligible = []
    for r in rows:
        if r["review_date"] != "-":
            continue
        try:
            added = date.fromisoformat(r["added_date"])
        except ValueError:
            continue
        if added <= cutoff:
            eligible.append(r)

    if not eligible:
        print(
            "暂无需要复习的题目（所有题目要么太新要么已复习）。", file=sys.stderr
        )
        sys.exit(1)

    chosen = random.choice(eligible)

    # Update review_date in the file
    with open(REVIEW_FILE, "r", encoding="utf-8") as f:
        content = f.read()

    # Replace the matching row's review_date
    old_row_pat = re.compile(
        rf"^(\|\s*{re.escape(str(chosen['id']))}\s*\|\s*{re.escape(chosen['title'])}\s*\|\s*{re.escape(chosen['added_date'])}\s*\|\s*)-(\s*\|)$",
        re.MULTILINE,
    )
    new_line = rf"\1{today.isoformat()}\2"
    content, count = old_row_pat.subn(new_line, content)

    if count > 0:
        with open(REVIEW_FILE, "w", encoding="utf-8") as f:
            f.write(content)

    json.dump(
        {
            "id": chosen["id"],
            "title": chosen["title"],
            "added_date": chosen["added_date"],
        },
        sys.stdout,
        ensure_ascii=False,
    )
    sys.stdout.write("\n")


if __name__ == "__main__":
    main()
