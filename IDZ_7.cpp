#include <iostream>
#include <cmath>

long long fi(int n) {
    return n <= 2 ? 1 : fi(n - 1) + fi(n - 2);
}

long long fii(int n) {
    if (n <= 2) return 1;
    long long a = 1, b = 1;
    for (int i = 3; i <= n; ++i) {
        b += a;
        a = b - a;
    }
    return b;
}

int main() {
    const double alpha = (1 + std::sqrt(5)) / 2;
    const double eps = 1e-5;
    
    int n_rec = 2;
    while (true) {
        long long fn = fi(n_rec);
        long long fn1 = fi(n_rec + 1);
        double ratio = static_cast<double>(fn1) / fn;
        if (std::abs(ratio - alpha) < eps) {
            std::cout << "Рекурсивный метод: n = " << n_rec << std::endl;
            break;
        }
        if (n_rec > 40) {
            std::cout << "Рекурсивный метод не достиг точности до n=40" << std::endl;
            break;
        }
        n_rec++;
    }
    
    int n_iter = 2;
    while (true) {
        long long fn = fii(n_iter);
        long long fn1 = fii(n_iter + 1);
        double ratio = static_cast<double>(fn1) / fn;
        if (std::abs(ratio - alpha) < eps) {
            std::cout << "Итеративный метод: n = " << n_iter << std::endl;
            break;
        }
        n_iter++;
    }
    
    return 0;
}
