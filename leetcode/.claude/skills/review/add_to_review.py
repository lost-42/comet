#!/usr/bin/env python3
"""Add a problem to the review list (review.md in project root).

Usage:
    python3 add_to_review.py <problem_id> "<title>"
"""

import os
import sys
from datetime import date

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REVIEW_FILE = os.path.join(SCRIPT_DIR, "review.md")


def main():
    if len(sys.argv) < 3:
        print("Usage: add_to_review.py <problem_id> <title>", file=sys.stderr)
        sys.exit(1)

    pid = sys.argv[1]
    title = sys.argv[2]
    today = date.today().isoformat()

    if not os.path.exists(REVIEW_FILE):
        header = (
            "# LeetCode 复习列表\n\n"
            "| # | 标题 | 加入日期 | 复习日期 |\n"
            "|---|------|----------|----------|\n"
        )
    else:
        header = ""

    new_row = f"| {pid} | {title} | {today} | - |\n"

    with open(REVIEW_FILE, "a", encoding="utf-8") as f:
        f.write(header + new_row)

    print(f"已添加 #{pid} {title} 到复习列表")


if __name__ == "__main__":
    main()
