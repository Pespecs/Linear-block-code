# Linear Block Code Analyzer

A C++ application for analyzing Linear Block Codes in Information Theory and Coding Theory courses.

The program supports:

- Verifying whether a given set of binary vectors forms a valid Linear Block Code.
- Generating all valid codewords from a parity-check matrix using Gaussian Elimination over GF(2).
- Multiple output modes for both educational and competitive programming purposes.

---

# Features

## Task A — Linear Block Code Verification

Checks whether a given set of binary vectors forms a valid Linear Block Code by verifying:

1. Presence of the all-zero codeword.
2. Closure under XOR operation.

---

## Task B — Codeword Generation from Parity Check Matrix

Given a parity-check matrix \(H\), the program:

- Computes the null space over GF(2).
- Uses Gaussian Elimination.
- Generates all valid codewords satisfying:

\[
Hc^T = 0
\]

Supports both systematic and non-systematic matrices.

---

# Output Modes

## `F` — Full Explanation Mode

Produces detailed step-by-step explanations suitable for:

- Self-study
- Reports
- Essay-style solutions
- Teaching demonstrations

Example:

```text
1. Checking for the all-zero codeword...
2. Checking closure under XOR...
Conclusion: The code IS linear.
```

---

## `M` — Minimal / ICPC Mode

Produces clean standard output suitable for:

- ICPC-style testing
- Automated grading
- Multiple-choice answer generation

Example:

```text
Linear
```

or

```text
0000
1010
0101
1111
```

---

# Input Format

The program reads continuously until EOF.

Each test case starts with:

```text
<TaskType> <OutputMode>
```

Where:

- `TaskType`:
  - `A` → Linearity Verification
  - `B` → Codeword Generation

- `OutputMode`:
  - `F` → Full Explanation
  - `M` → Minimal / ICPC

---

# Task A Input

```text
A F
N
codeword_1
codeword_2
...
codeword_N
```

### Example

```text
A M
4
000
011
101
110
```

---

# Task B Input

```text
B F
R C
H11 H12 ... H1C
H21 H22 ... H2C
...
HR1 HR2 ... HRC
```

Where:

- `R` = number of rows of \(H\)
- `C` = number of columns of \(H\)

### Example

```text
B M
2 4
1 0 1 1
0 1 1 0
```

---

# Compilation

Compile using g++:

```bash
g++ -std=c++17 -O2 main.cpp -o analyzer
```

---

# Execution

## Linux / macOS

```bash
./analyzer < input.in > output.out
```

## Windows

```bash
analyzer < input.in > output.out
```

---

# Project Structure

```text
.
├── main.cpp
├── input.in
├── output.out
└── README.md
```

---

# Algorithms Used

- Gaussian Elimination over GF(2)
- Null Space Computation
- XOR Closure Verification
- Binary Linear Algebra

---

# Complexity Analysis

## Task A

\[
O(M^2 \cdot N)
\]

Where:

- \(M\) = number of codewords
- \(N\) = codeword length

---

## Task B

Gaussian Elimination:

\[
O(R \cdot C^2)
\]

Codeword Generation:

\[
O(2^k \cdot C)
\]

Where:

- \(k\) = dimension of the code

---

# Notes

- Fully compatible with ICPC-style input/output.
- Supports multiple test cases.
- Uses only standard C++17 libraries.
- Educational and competitive-programming friendly.

---

# Authors

Information Theory / Coding Theory Group Project
