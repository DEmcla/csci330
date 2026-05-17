# The Weekly Defense & Co-Examiner Guide

CSCI 330 has a **mandatory weekly synchronous meeting** — about one hour, on a
fixed mid-week day, in every offering of the course (both the short, intensive
pace and the full-semester pace). This guide explains what that meeting is, how
to prepare for it, and what is expected of you whether you are defending your
own work or co-examining a classmate's.

## The meeting is a defense

The weekly meeting is a **defense of your own work** — not a code-review ritual,
not a lecture. Each week it works through the *previous* week's homework: you
explain what you built, why you built it that way, and answer questions about
it live. The instructor leads the questioning; your classmates join in as
co-examiners.

This is how the course verifies that the work is yours and that you understand
it. You may use AI to help you *write* code and to help you *prepare* for the
defense — that is fine and expected. What you cannot do is outsource the live
conversation. If you understand what you submitted, the defense is
straightforward.

## How a meeting runs

- **About 4 students defend each meeting**, **chosen by random call** from the
  section. You will not know in advance whether this is your week.
- Because the call is random, **every student must arrive prepared every
  week.** Being prepared — not being called — is the obligation. Treat each
  week's homework as something you may have to defend on the spot.
- **Week 1 has no defense** (there is no prior homework yet). The final week's
  homework is graded normally but is not defended.
- The meeting is graded as part of your **Participation** grade (30% of the
  course). Both defending well and co-examining well count.

## At the three capstone phase-anchor weeks

Most weeks the meeting defends homework, and the capstone runs underneath as
async work. But at the **three capstone phase-anchor weeks (Chapters 5, 11, and
17)**, the meeting becomes a **capstone-phase defense** instead: you present and
defend that phase of your project, and classmates co-examine it. **Phase 3's
defense is the final project presentation.** Phase deliverables are due a few
days before the defense meeting so you are not finishing a phase and prepping a
defense on the same day.

## If you are defending

When it is your turn, expect to:

- **Walk through your code** — including a **function of the instructor's
  choosing**, not just the part you are most proud of. Be ready to explain any
  part of what you submitted.
- **Justify a design decision** — why you structured it this way, what you
  considered and rejected, what the trade-off was.
- **Answer the co-examiner question set** below, plus live follow-up questions.

Preparation: re-read your own code before the meeting. If a part of it only
worked because AI suggested it, make sure you understand *why* it works. The
defense rewards understanding, not memorized scripts.

## If you are co-examining

When you are not defending, you are a **co-examiner** — not a passive observer
and not an independent reviewer. You arrive with questions and observations and
**join the questioning** of whoever is defending.

To make this possible, the defending students **share their code in advance**.
Read it before the meeting — you cannot review code cold in a one-hour session.
Come with at least one specific question or observation per defender.

Co-examination counts toward your Participation grade. Substantive questions
that move the discussion forward count; silence and "looks fine to me" do not.

## The co-examiner question set

These five questions are **fixed and published**. Use them to prepare your
questions for every defense. The defending student knows these questions are
coming.

1. **Comprehension** — In your own words, what does this code do?
2. **Correctness** — Does it do what the assignment or feature requires? Find a
   case where it would not.
3. **Risk** — Name one input or situation it does not handle well.
4. **Improvement** — Suggest one concrete change (naming, structure, a C++
   idiom).
5. **Strength** — Name one thing it does well.

**Weak co-examination:** "Looks good." / "I don't have any questions."

**Useful co-examination:** "What happens if the input file is empty — does the
loop on line 30 still terminate?" / "The `Buffer` move constructor leaves the
source at `size = 0`, which is exactly right — was that deliberate?"

## What to expect and what not to do

- **Defending:** be ready to discuss *any* part of your submission, including a
  function the instructor picks. Do not assume you can steer the conversation to
  your strongest code.
- **Co-examining:** ask real questions and be specific. Do not be harsh — you
  are helping a classmate understand their own work better, and they
  co-examine you in turn.
- **Either role:** arrive prepared. The random call means there is no week off.
