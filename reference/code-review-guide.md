# Giving a Useful Code Review

In this course, peer review is not a form — it is a real **GitHub code review**
on a classmate's Pull Request. Reviewing code is half of the professional Git
workflow, and it is a graded part of your participation.

## When you review

At each capstone phase checkpoint you are assigned classmates' PRs to review.
Substantive reviews count toward the **20% participation** grade; a one-line
"looks good!" earns little.

## How to leave a GitHub review

1. Open the assigned PR and click the **Files changed** tab.
2. Hover over a line of code and click the blue **+** to leave an **inline
   comment** on that specific line.
3. When done, click **Review changes**, write a short **summary**, and submit.

## What makes a review useful

A useful review is **specific** and **kind**. Aim for:

- Two or three **inline comments** tied to actual lines — a question, a
  suggestion, a spotted bug, or genuine praise for something done well.
- A **summary** that says what works and the one thing you would change.
- Comments that explain *why*, so they help the author improve.

**Weak:** "Looks good." / "Nice work!"

**Useful:** "Line 42 — this `new` has no matching `delete`; the destructor would
fix the leak." / "The `Buffer` move constructor is clean — leaving the source at
`size = 0` is exactly right."

## What not to do

- Do not rewrite their code for them — review it.
- Do not approve work you did not actually read.
- Do not be harsh. You are helping a classmate, and they review you back.
