#include <iostream>
#include <cmath> // Thư viện hỗ trợ toán học
using namespace std;

// Hàm tính giai thừa của một số nguyên
double factorial(int n) {
    double fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Hàm tính sin(x) bằng chuỗi Taylor
double sinTaylor(double x) {
    double term = x; // Số hạng đầu tiên
    double sum = x;  // Tổng ban đầu là số hạng đầu tiên
    int n = 1;
    
    while (fabs(term) > 0.00001) { // Lặp đến khi số hạng nhỏ hơn 0.00001
        term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        sum += term;
        n++;
    }
    
    return sum;
}

int main() {
    double x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    
    double result = sinTaylor(x);
    cout << "Gia tri sin(" << x << ") = " << result << endl;
    
    return 0;
}
