#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Tối ưu hóa cực đại I/O cho dữ liệu lớn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Dùng long long cho TẤT CẢ các biến quan trọng để đề phòng testcase vượt quá giới hạn int
    long long n, k;
    
    // Đọc input an toàn
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long current_sum = 0;
    long long max_len = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += a[right];

        // Thu hẹp cửa sổ nếu tổng vượt k. 
        // Điều kiện left <= right đảm bảo left không bao giờ vượt quá right + 1
        while (current_sum > k && left <= right) {
            current_sum -= a[left];
            left++;
        }

        // Chốt kiểm tra an toàn 100% trước khi cập nhật kỷ lục
        if (current_sum <= k) {
            long long current_len = right - left + 1;
            if (current_len > max_len) {
                max_len = current_len;
            }
        }
    }

    cout << max_len << "\n";

    return 0;
}
