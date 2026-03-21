#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu hóa tốc độ đọc/ghi dữ liệu trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 1. Sắp xếp mảng tăng dần
    sort(a.begin(), a.end());

    // 2. Tìm phần tử xuất hiện nhiều nhất
    int max_freq = 0;
    int best_val = a[0];
    int best_first_idx = 1;

    int current_freq = 1;
    int current_first_idx = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            current_freq++; // Nếu giống phần tử trước, tăng bộ đếm
        } else {
            // Nếu khác, kiểm tra xem tần suất của phần tử trước có lớn hơn kỷ lục không
            if (current_freq > max_freq) {
                max_freq = current_freq;
                best_val = a[i - 1];
                best_first_idx = current_first_idx;
            }
            // Reset lại tần suất và cập nhật vị trí bắt đầu của phần tử mới
            current_freq = 1;
            current_first_idx = i + 1; // Vị trí đánh số từ 1
        }
    }

    // Kiểm tra lần cuối cho phần tử nằm ở cuối mảng
    if (current_freq > max_freq) {
        max_freq = current_freq;
        best_val = a[n - 1];
        best_first_idx = current_first_idx;
    }

    // 3. In kết quả ra 2 dòng
    cout << best_val << "\n";
    cout << best_first_idx << "\n";

    return 0;
}
