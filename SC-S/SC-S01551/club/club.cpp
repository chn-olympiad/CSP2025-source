#include <bits/stdc++.h>
using namespace std;
struct node{
	int id, s;
};
node l[1001], b[1001], c[1001];
bool cmp(node x, node y){
	return x.s > y.s;
}
bool vis[1001];
int n, maxn, a[10001][4];
void dfs(int k, int u, int t1, int t2, int t3){
	if(t1 > n / 2 || t2 > n / 2 || t3 > n / 2){
		return;
	}
	if(u == n){
		maxn = max(maxn, k);
		return;
	}
	u++;
	for(int i = 1; i <= 3; i++){
		if(i == 1){
			dfs(k + a[u][i], u, t1 + 1, t2, t3);
		}else if(i == 2){
			dfs(k + a[u][i], u, t1, t2 + 1, t3);
		}else if(i == 3){
			dfs(k + a[u][i], u, t1, t2, t3 + 1);
		}
		
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		maxn = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		if(n >= 200){
			if(a[0][2] == 0){
				int t[100001];
				for(int i = 1; i <= n; i++){
					t[i] = a[i][1];
				}
				long long sum = 0;
				sort(t + 1, t + n + 1, greater<int>());
				for(int i = 1; i <= n/2; i++){
					sum += t[i];
				}
				cout << sum << endl;
				continue;
			}else{
				
			}
		}
		dfs(0, 0, 0, 0, 0);
		cout << maxn << endl;
		/*sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp);
		sort(c + 1, c + n + 1, cmp);
		int sum = 0;
		
		memset(vis, 0, sizeof(vis));
		int top1 = 1, top2 = 1, top3 = 1;
		while(top1 <= n && top2 <= n && top3 <= n){
			while(vis[a[top1].id]){
				top1++;
			}
			while(vis[b[top2].id]){
				top2++;
			}
			while(vis[c[top3].id]){
				top3++;
			}
			if(a[top1].s >= b[top2].s && a[top1].s >= c[top3].s && top1 <= n / 2){
				vis[a[top1].id] = 1;
				sum += a[top1].s;
				top1++;
			}else if(b[top2].s >= a[top1].s && b[top2].s >= c[top3].s && top2 <= n / 2){
				vis[b[top2].id] = 1;
				sum += b[top2].s;
				top2++;
			}else{
				vis[c[top3].id] = 1;
				sum += c[top3].s;
				top3++;
			}
		}
		cout << sum << endl;*/
	}
	return 0;
} 