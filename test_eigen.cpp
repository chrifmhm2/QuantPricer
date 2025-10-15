#include <Eigen/Dense>
#include <iostream>

int main() {
    Eigen::MatrixXd A(2,2);
    A << 3, 2,
         1, 4;

    Eigen::VectorXd b(2);
    b << 5, 6;

    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);

    std::cout << "Solution: " << x.transpose() << std::endl;
    return 0;
}
