#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int arr[100010][3];
int mx[100010][3];
int nw[100010];
struct node {
	int x, dis;
};

bool operator < (node a, node b) {
	return a.dis < b.dis;
}
bool operator > (node a, node b) {
	return a.dis > b.dis;
}

priority_queue<node, vector<node>, greater<node> > q[3];

void ist(int e, int l) {
	if (q[l].size() < n / 2) {
		q[l].push({e, arr[e][mx[e][nw[e]]] - arr[e][mx[e][nw[e] + 1]]});
		return;
	}
	int tp = q[l].top().x;
	if (arr[e][mx[e][nw[e]]] + arr[tp][mx[tp][nw[tp] + 1]] > arr[e][mx[e][nw[e] + 1]] + arr[tp][mx[tp][nw[tp]]]) {
		q[l].pop();
		q[l].push({e, arr[e][mx[e][nw[e]]] - arr[e][mx[e][nw[e] + 1]]});
		nw[tp]++;
		ist(tp, mx[tp][nw[tp]]);
	}
	else {
		nw[e]++; 
		ist(e, mx[e][nw[e]]); 
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", arr[i], arr[i] + 1, arr[i] + 2);
			if (arr[i][0] >= arr[i][1] && arr[i][0] >= arr[i][2]) {
				mx[i][0] = 0;
				if (arr[i][1] >= arr[i][2])
					mx[i][1] = 1, mx[i][2] = 2;
				else
					mx[i][1] = 2, mx[i][2] = 1;
			}
			else if (arr[i][1] >= arr[i][0] && arr[i][1] >= arr[i][2]) {
				mx[i][0] = 1;
				if (arr[i][0] >= arr[i][2])
					mx[i][1] = 0, mx[i][2] = 2;
				else
					mx[i][1] = 2, mx[i][2] = 0;
			}
			else {
				mx[i][0] = 2;
				if (arr[i][0] >= arr[i][1])
					mx[i][1] = 0, mx[i][2] = 1;
				else
					mx[i][1] = 1, mx[i][2] = 0;
			}
			nw[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			ist(i, mx[i][nw[i]]);
		}
		int ans = 0;
		while(!q[0].empty()) {
			int t = q[0].top().x;
			ans += arr[t][0];
			q[0].pop();
		}
		while(!q[1].empty()) {
			int t = q[1].top().x;
			ans += arr[t][1];
			q[1].pop();
		}
		while(!q[2].empty()) {
			int t = q[2].top().x;
			ans += arr[t][2];
			q[2].pop();
		}
		printf("%d\n", ans);
	}	
	return 0;
}
