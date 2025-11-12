#define file_io(id) do { \
    freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); } while(false)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int MAXN = 1e5 + 10;

int t, n;
int a[MAXN][4];
int first[MAXN], secondary[MAXN];
vector<int> delta;

int main() {
	file_io("club");
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> t;
	while (t--) {
        int ans = 0, cnt[4] = {0, 0, 0, 0};
        delta.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i][1] >> a[i][2] >> a[i][3];

        for (int i = 1; i <= n; i++) {
            int tmp = -0x3f3f3f3f;
            for (int j = 1; j <= 3; j++)
                if (a[i][j] >= tmp) tmp = a[i][j], first[i] = j;
            ans += tmp, tmp = -0x3f3f3f3f, cnt[first[i]]++;
            for (int j = 1; j <= 3; j++)
                if (a[i][j] >= tmp && j != first[i]) secondary[i] = j, tmp = a[i][j];
        }

        for (int i = 1; i <= 3; i++) {
            if (cnt[i] > n / 2) {
                int d = cnt[i] - n / 2, cnt = 0;
                for (int j = 1; j <= n; j++)
                    if (first[j] == i) delta.push_back(a[j][first[j]] - a[j][secondary[j]]);
                sort(delta.begin(), delta.end());
                for (int i = 0; i < d; i++) ans -= delta[i];
            }
        }

        cout << ans << "\n";
	}

	return 0;
}
