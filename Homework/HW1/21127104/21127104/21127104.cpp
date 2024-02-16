#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

void multiply(const vector<vector<int>>& a, const vector<vector<int>>& b, vector<vector<int>>& c, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    vector<int> N = { 10, 25, 50, 75, 100, 250, 500, 750, 1000, 1250 };

    vector<double> elapsed_times; // Danh sách để lưu thời gian thực thi

    for (int n : N) {
        vector<vector<int>> A(n, vector<int>(n, 1));
        vector<vector<int>> B(n, vector<int>(n, 2));
        vector<vector<int>> C(n, vector<int>(n, 0));

        high_resolution_clock::time_point t1 = high_resolution_clock::now(); // Thời điểm bắt đầu

        multiply(A, B, C, n);

        high_resolution_clock::time_point t2 = high_resolution_clock::now(); // Thời điểm kết thúc

        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        double elapsed_secs = time_span.count();

        elapsed_times.push_back(elapsed_secs);

        cout << "C++ Execution Time for N = " << n << ": " << elapsed_secs << " seconds" << endl;
    }

    return 0;
}
