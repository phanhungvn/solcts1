#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    // Tối ưu hóa I/O cho dữ liệu lớn
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // Dùng danh sách kề để biểu diễn đồ thị vô hướng
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Đồ thị vô hướng nên phải thêm cả 2 chiều
    }

    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, -1); // Lưu khoảng cách từ đỉnh 1

    // 1. Chạy BFS từ đỉnh 1
    queue<int> q;
    q.push(1);
    visited[1] = true;
    dist[1] = 0;

    int components = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    // Đã duyệt xong thành phần liên thông chứa đỉnh 1
    components++; 

    // 2. Kiểm tra xem đồ thị có liên thông toàn bộ không
    bool connected = true;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            connected = false;
            
            // Nếu có đỉnh chưa thăm, ta đếm thêm 1 thành phần liên thông
            // và tiếp tục chạy BFS/DFS để đánh dấu hết vùng đó
            components++;
            q.push(i);
            visited[i] = true;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }

    // 3. In kết quả theo yêu cầu
    if (connected) {
        cout << "Connected\n";
        cout << dist[n] << "\n";
    } else {
        cout << "Not connected\n";
        cout << components << "\n";
    }

    return 0;
}
