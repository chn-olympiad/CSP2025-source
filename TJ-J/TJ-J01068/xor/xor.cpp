#define file_io(id) do { \
    freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); } while(false)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAXN = 5e5 + 10;

int n, k;
int a[MAXN], s[MAXN];
long long ans = 1;

struct interval {
    int x; int y;
};

vector<interval> intervals;

bool cmp(interval x, interval y) {
    return x.y < y.y;
}

int main() {
    file_io("xor");
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] ^ a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++)
            if ((s[j] ^ s[i - 1]) == k) { intervals.push_back({i, j}); break; }
    }

    sort(intervals.begin(), intervals.end(), cmp);
    int last = intervals.front().y;
    for (int i = 1; i < intervals.size(); i++)
        if (intervals[i].x > last) ans++, last = intervals[i].y;

    cout << ans << endl;
	return 0;
}

