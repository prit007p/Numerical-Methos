# Numerical Methods C++ Programs

This repository contains C++ implementations of various **numerical methods** commonly used in engineering, mathematics, and scientific computing. Each program is self-contained and demonstrates a fundamental numerical technique.

---

## Table of Contents

1. [Bisection Method](bisection_method.cpp)  
2. [Fixed Point Iteration](fixed_point_iteration.cpp)  
3. [Newton–Raphson Method](newton-rapson.cpp)  
4. [Gauss Elimination](gauss_elim.cpp)  
5. [Gauss–Jordan Elimination](gauss_jordon.cpp)  
6. [Jacobi Method](jacobi_nethod.cpp)  
7. [LU Decomposition](LU.cpp)  
8. [Matrix Inversion](matrix_inversion.cpp)  
9. [Power Method](power_method.cpp)  
10. [Monte Carlo Integration](monte_carglo.cpp)  
11. [Runge–Kutta 4th Order](range_kutta.cpp)  
12. [Relaxation (SOR) Method](relaxtion_method.cpp)  
13. [Simpson 1/3 Rule](simpson.cpp)  
14. [Matrix Multiplication](matrix_multiplication.cpp)  

---

## 1. Bisection Method

**Purpose:** Find a root of an equation `f(x) = 0` using interval halving.  
**File:** [bisection_method.cpp](bisection_method.cpp)

---

## 2. Fixed Point Iteration

**Purpose:** Solve `x = g(x)` iteratively.  
**File:** [fixed_point_iteration.cpp](fixed_point_iteration.cpp)

---

## 3. Newton–Raphson Method

**Purpose:** Solve `f(x) = 0` using derivative-based iteration.  
**File:** [newton-rapson.cpp](newton-rapson.cpp)

---

## 4. Gauss Elimination

**Purpose:** Solve a system of linear equations `Ax = b` using forward elimination and back substitution.  
**File:** [gauss_elim.cpp](gauss_elim.cpp)

---

## 5. Gauss–Jordan Elimination

**Purpose:** Solve `Ax = b` using Gauss–Jordan elimination (Reduced Row Echelon Form).  
**File:** [gauss_jordon.cpp](gauss_jordon.cpp)

---

## 6. Jacobi Method

**Purpose:** Iteratively solve `Ax = b` using Jacobi iteration.  
**File:** [jacobi_nethod.cpp](jacobi_nethod.cpp)

---

## 7. LU Decomposition

**Purpose:** Solve `Ax = b` by decomposing `A = L * U`.  
**File:** [LU.cpp](LU.cpp)

---

## 8. Matrix Inversion

**Purpose:** Find the inverse of a square matrix `A` using Gauss–Jordan elimination.  
**File:** [matrix_inversion.cpp](matrix_inversion.cpp)

---

## 9. Power Method

**Purpose:** Find the dominant eigenvalue and eigenvector of a matrix.  
**File:** [power_method.cpp](power_method.cpp)

---

## 10. Monte Carlo Integration

**Purpose:** Approximate definite integral `∫ f(x) dx` using random sampling.  
**File:** [monte_carglo.cpp](monte_carglo.cpp)

---

## 11. Runge–Kutta 4th Order (RK4)

**Purpose:** Solve first-order ODE `dy/dx = f(x, y)` with initial condition `y(x0) = y0`.  
**File:** [range_kutta.cpp](range_kutta.cpp)

---

## 12. Relaxation (SOR) Method

**Purpose:** Solve `Ax = b` iteratively with relaxation factor `ω` to accelerate convergence.  
**File:** [relaxtion_method.cpp](relaxtion_method.cpp)

---

## 13. Simpson 1/3 Rule

**Purpose:** Numerical integration using Simpson’s 1/3 formula.  
**File:** [simpson.cpp](simpson.cpp)

---

## 14. Matrix Multiplication

**Purpose:** Multiply two matrices `C = A * B`.  
**File:** [matrix_multiplication.cpp](matrix_multiplication.cpp)

---

## Usage

# Compile any C++ file
g++ filename.cpp -o program

# Run the executable
./program

# Follow on-screen prompts to input the data

## Notes

- Some methods (like Simpson 1/3, Bisection, Monte Carlo) use example functions in the code which can be modified.
- Jacobi and Relaxation methods require diagonally dominant matrices for guaranteed convergence.
- Always ensure matrix dimensions are compatible for multiplication or inversion.
- The Table of Contents links directly to the corresponding `.cpp` files in this repository.
