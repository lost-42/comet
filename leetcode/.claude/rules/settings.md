---
name: tracked-settings-only
description: All Claude Code settings must go to tracked .claude/settings.json, never to settings.local.json
metadata:
  type: feedback
---

Always write configuration changes to `.claude/settings.json` (tracked by Git). Never create or write to `.claude/settings.local.json` (gitignored, won't travel with the repo). This repository is used by a single developer across multiple devices — all settings must be portable.

**Why:** `settings.local.json` is gitignored and won't follow the repo to other devices. Since this is a single-user project, every setting should be synced via Git.

**How to apply:** Whenever modifying permissions, hooks, env vars, or any other Claude Code settings, only edit `.claude/settings.json`. If `.claude/settings.local.json` exists on a device, migrate its contents to `.claude/settings.json` first, then delete it.
