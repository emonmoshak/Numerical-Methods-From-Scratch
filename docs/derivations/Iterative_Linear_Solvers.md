# Iterative Linear Solvers: Jacobi and Gauss-Seidel

Iterative methods solve $Ax = b$ by starting from an initial guess and refining it until convergence.

## Jacobi Method

The Jacobi method decomposes $A$ into $A = D + R$, where $D$ is the diagonal part and $R$ is the rest (sum of strictly lower $L$ and upper $U$ triangular matrices).

The iteration is:
$x^{(k+1)} = D^{-1} (b - R x^{(k)})$

Component-wise:
$x_i^{(k+1)} = \frac{1}{a_{ii}} \left( b_i - \sum_{j \neq i} a_{ij} x_j^{(k)} \right)$

## Gauss-Seidel Method

The Gauss-Seidel method uses the most recently updated values as soon as they are available.

The iteration is:
$x_i^{(k+1)} = \frac{1}{a_{ii}} \left( b_i - \sum_{j < i} a_{ij} x_j^{(k+1)} - \sum_{j > i} a_{ij} x_j^{(k)} \right)$

Matrix form: $(D + L) x^{(k+1)} = b - U x^{(k)}$

## Convergence Analysis

Both methods converge if the matrix $A$ is **strictly diagonally dominant**:
$|a_{ii}| > \sum_{j \neq i} |a_{ij}|$ for all $i$.

Gauss-Seidel typically converges faster than Jacobi.

## Complexity Analysis

Each iteration takes $O(n^2)$ operations. For $m$ iterations, the total complexity is $O(m \cdot n^2)$. If $m \ll n$, these methods are faster than direct solvers ($O(n^3)$).

## Stability Discussion

Iterative solvers are generally more stable for large, sparse matrices and less sensitive to round-off errors than direct methods. However, if the matrix is not diagonally dominant, they may diverge.
