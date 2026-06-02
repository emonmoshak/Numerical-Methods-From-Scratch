# LU Decomposition

LU Decomposition factors a square matrix $A$ into the product of a lower triangular matrix $L$ and an upper triangular matrix $U$.

$A = LU$

## Mathematical Derivation

For a $3 \times 3$ matrix $A$:
$\begin{pmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{pmatrix} = \begin{pmatrix} 1 & 0 & 0 \\ l_{21} & 1 & 0 \\ l_{31} & l_{32} & 1 \end{pmatrix} \begin{pmatrix} u_{11} & u_{12} & u_{13} \\ 0 & u_{22} & u_{23} \\ 0 & 0 & u_{33} \end{pmatrix}$

The elements can be found using Doolittle's algorithm:
1. $u_{ij} = a_{ij} - \sum_{k=1}^{i-1} l_{ik} u_{kj}$ for $i \leq j$
2. $l_{ij} = \frac{1}{u_{jj}} \left( a_{ij} - \sum_{k=1}^{j-1} l_{ik} u_{kj} \right)$ for $i > j$

### Solving Linear Systems

Once $A$ is decomposed into $LU$, the system $Ax = b$ can be solved in two steps:
1. Solve $Ly = b$ using forward substitution.
2. Solve $Ux = y$ using backward substitution.

## Complexity Analysis

- **Decomposition**: $O(\frac{2}{3}n^3)$ operations.
- **Substitution**: $O(n^2)$ for each (forward and backward).

Total complexity for one system is $O(n^3)$. Subsequent systems with the same $A$ but different $b$ take only $O(n^2)$.

## Stability Discussion

LU decomposition without pivoting can be unstable if a pivot element $u_{jj}$ is very small or zero. Partial pivoting ($PA = LU$) is typically used to ensure stability by swapping rows to ensure the largest element in the current column is on the diagonal.
