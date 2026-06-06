#!/usr/bin/env python3
"""Fetch LeetCode problem data from leetcode.cn GraphQL API.

Usage:
    python3 fetch_problem.py <title-slug>      # output JSON to stdout
    python3 fetch_problem.py --has-content <title-slug>  # exit 0 iff accessible (non-VIP)

Fields returned (JSON):
    questionId, questionFrontendId, translatedTitle, translatedContent,
    codeSnippets[{lang, langSlug, code}], exampleTestcases

Exit codes:
    0 - success
    1 - usage error or network failure
    2 - VIP problem (question or translatedContent is null)
"""

import json
import sys
import urllib.error
import urllib.request

GRAPHQL_URL = "https://leetcode.cn/graphql"

QUERY = """
query questionData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionId
    questionFrontendId
    translatedTitle
    translatedContent
    codeSnippets { lang langSlug code }
    exampleTestcases
  }
}
"""


def fetch(title_slug: str) -> dict:
    """Fetch problem data. Raises SystemExit(2) if VIP-only."""
    data = json.dumps({
        "query": QUERY,
        "variables": {"titleSlug": title_slug},
    }).encode("utf-8")

    req = urllib.request.Request(
        GRAPHQL_URL,
        data=data,
        headers={"Content-Type": "application/json"},
    )

    try:
        with urllib.request.urlopen(req) as resp:
            result = json.loads(resp.read().decode("utf-8"))
    except urllib.error.URLError as e:
        print(f"Network error: {e}", file=sys.stderr)
        sys.exit(1)

    question = result.get("data", {}).get("question")

    if question is None or question.get("translatedContent") is None:
        sys.exit(2)

    return question


if __name__ == "__main__":
    args = sys.argv[1:]

    if not args:
        print("Usage: fetch_problem.py [-o <outfile>] <title-slug>", file=sys.stderr)
        sys.exit(1)

    outfile = None
    if args[0] == "-o":
        if len(args) < 3:
            print("Usage: fetch_problem.py [-o <outfile>] <title-slug>", file=sys.stderr)
            sys.exit(1)
        outfile = args[1]
        args = args[2:]

    if not args:
        print("Usage: fetch_problem.py [-o <outfile>] <title-slug>", file=sys.stderr)
        sys.exit(1)

    if args[0] == "--has-content":
        slug = args[1] if len(args) > 1 else ""
        if not slug:
            print("Usage: fetch_problem.py --has-content <title-slug>", file=sys.stderr)
            sys.exit(1)
        fetch(slug)  # exits 2 if VIP
        sys.exit(0)
    else:
        slug = args[0]
        question = fetch(slug)
        if outfile:
            with open(outfile, "w", encoding="utf-8") as f:
                json.dump(question, f, ensure_ascii=False, indent=2)
        else:
            json.dump(question, sys.stdout, ensure_ascii=False, indent=2)
