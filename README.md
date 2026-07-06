# GPA & CGPA Calculator

A simple command-line C++ program that calculates a student's semester GPA and updates their overall CGPA based on previously earned credits.

## Features

- Takes input for the number of courses taken in the current semester
- Accepts credit hours and grade for each course
- Validates input (rejects zero/negative credit hours and invalid grade entries, asking the user to re-enter)
- Converts grades (A+ to F) into grade points using a standard 4.0 scale
- Calculates:
  - **Semester GPA** — based on the current semester's courses
  - **Overall CGPA** — combines the student's previous CGPA and earned credits with the current semester's results
- Displays a formatted transcript showing each course's credit hours, grade points, and letter grade, along with the final GPA and CGPA

## Grading Scale

This GPA Calculator uses **FAST University's** standard Grading Scale

## Program Structure

The code is organized into functions, each function has its own responsibility

| Function | Purpose |
|----------|---------|
| `inputData()` | Ask the user to enter credit hours and grades for each course, with input validation |
| `calculateGradePoints()` | Converts each course's letter grade into its specific grade point |
| `calculateGPA()` | Calculate total credit hours, total grade points, and the semester GPA |
| `calculateCGPA()` | Combines current semester results with previous CGPA/credits to calculate the updated CGPA |
| `displayTranscript()` | Prints a formatted summary table of all courses along with the final GPA and CGPA |

## Notes (Points to Remember)

- Credit hours must be a positive number; the program will re-prompt if `0` or a negative value is entered.
- Only valid letter grades (A+ through D, and F) are accepted; invalid entries prompt the user to re-enter.
- `.exe` build artifacts are excluded from version control via `.gitignore`.
