#include <bits/stdc++.h>

#define int long long

std::array<int, 3> rank(const std::array<int, 3>& arr) {
    std::array<int, 3> res = {0, 1, 2};
    std::sort(res.begin(), res.end(), [&](int a, int b) {
        return arr[a] > arr[b];
    });
    return res;
}

void avr(std::priority_queue<int>& pq, int& sum, int lim) {
    while (pq.size() > lim) {
        sum += pq.top();
        pq.pop();
    }
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    std::cin >> t; 
    while (t--) {
        int n;
        std::cin >> n;
        int sum = 0;
        std::vector<std::array<int, 3>> a(n);
        std::priority_queue<int> pq[3];
        for (int i = 0; i < n; i++) {
            std::cin >> a[i][0] >> a[i][1] >> a[i][2];
            sum += std::max({a[i][0], a[i][1], a[i][2]});
            auto r = rank(a[i]);
            pq[r[0]].push(a[i][r[1]] - a[i][r[0]]);
        }
        avr(pq[0], sum, n / 2);
        avr(pq[1], sum, n / 2);
        avr(pq[2], sum, n / 2);
        std::cout << sum << '\n';
    }    
}

