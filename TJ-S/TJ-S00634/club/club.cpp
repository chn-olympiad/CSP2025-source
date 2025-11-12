#include <bits/stdc++.h>
using namespace std;

int se(int x, int y, int z) {
    return min(min(max(x, y), max(x, z)), max(y, z));
}
struct node {
    int id;
    int cha;
    bool operator < (const node &rhs) const {
        return cha > rhs.cha;
    }
};
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a[100005], b[100005], c[100005], sum = 0;
        priority_queue<node> team1;
        priority_queue<node> team2;
        priority_queue<node> team3;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &a[i], &b[i], &c[i]);

            int maxn = max(max(a[i], b[i]), c[i]);
            if (maxn == a[i]) {
                team1.push(node{i, a[i] - se(a[i], b[i], c[i])});
                sum += a[i];
            } else if (maxn == b[i]) {
                team2.push(node{i, b[i] - se(a[i], b[i], c[i])});
                sum += b[i];
            } else {
                team3.push(node{i, c[i] - se(a[i], b[i], c[i])});
                sum += c[i];
            }
        }
        while (team1.size() > n / 2) {
        	node now = team1.top();
        	team1.pop();

        	sum -= now.cha;
		}
		while (team2.size() > n / 2) {
        	node now = team2.top();
        	team2.pop();

        	sum -= now.cha;
		}
		while (team3.size() > n / 2) {
        	node now = team3.top();
        	team3.pop();

        	sum -= now.cha;
		}

		cout << sum << endl;
    }
    return 0;
}
