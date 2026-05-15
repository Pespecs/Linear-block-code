<<<<<<< HEAD
# Linear Block Code Analyzer

This C++ application is designed for Information Theory assignments and competitive programming environments. It provides tools to verify the linearity of block codes and deduce codeword spaces from arbitrary parity-check matrices.

**I/O Mechanism**: The program automatically reads input from `input.in` and writes output to `output.out` in the same directory.

## Features
- **Task A**: Verifies if a given set of binary vectors constitutes a valid Linear Block Code by checking the zero-vector and closure under XOR.
- **Task B**: Computes the null space of a given parity check matrix $H$ (systematic or non-systematic) over GF(2) using Gaussian Elimination and outputs all valid codewords.
- **Dual Output Modes**:
  - `F` (Full): Generates a detailed, step-by-step essay-style explanation suitable for self-study.
  - `M` (Multiple Choice / ICPC): Generates strict, clean standard output suitable for automated grading systems or MCQ answer generation.

## Input Format (ICPC Standard)

The program reads continuously from `input.in` until EOF. Each test case begins with two characters:
1. `Task Type`: `A` or `B`
2. `Output Mode`: `F` (Full) or `M` (Minimal/MCQ)

### For Task A:
- Character `A` followed by `F` or `M`.
- Integer `N` (number of codewords).
- `N` strings representing the binary codewords.

### For Task B:
- Character `B` followed by `F` or `M`.
- Integers `R` (number of rows in $H$) and `C` (number of columns in $H$).
- `R` lines, each containing `C` space-separated binary integers (0 or 1).

## Compilation & Execution

1. Create a file named `input.in` in the same folder as the source code and paste your test cases.
2. Compile and run the code:
```bash
g++ -O3 -std=c++17 main.cpp -o lbc_analyzer
./lbc_analyzer
=======
# Information-Thoery-part-2
Linear Block Code Analyzer
>>>>>>> 1c10e4d30dabebc276aa3d35a74fb904c1c2cbc4
