#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, MAXN = 209;
int a[N][5], p[N];
bool cmp(int x, int y){
	return x > y;
}
struct Node{
	int val, maxx;
	friend bool operator < (Node x, Node y){
		return x.val - x.maxx > y.val - y.maxx;
	}
};
priority_queue<Node> q[5], q1;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++) scanf("%d", &a[i][j]);
		}
		for(int i = 1; i <= 3; i++){
			while(!q[i].empty()) q[i].pop();
		}
		for(int i = 1; i <= n; i++){
			int maxx = 0;
			for(int j = 1; j <= 3; j++){
				maxx = max(maxx, a[i][j]);
			}
			for(int j = 1; j <= 3; j++){
				if(a[i][j] == maxx){
					if(j == 1){
						q[1].push({a[i][1], max(a[i][2], a[i][3])});
					}
					if(j == 2){
						q[2].push({a[i][2], max(a[i][1], a[i][3])});
					}
					if(j == 3){
						q[3].push({a[i][3], max(a[i][1], a[i][2])});
					}
					break;
				}
			}
		}
		int above = 0;
		for(int i = 1; i <= 3; i++){
			if((int)q[i].size() > n / 2) above = i;
		}
		ll ans = 0;
		for(int i = 1; i <= 3; i++){
			q1 = q[i];
			while(!q1.empty()) {
				ans += q1.top().val;
				q1.pop();
			}
		}
		if(above){
			while((int)q[above].size() > n / 2){
				Node x = q[above].top();
				ans -= x.val - x.maxx;
				q[above].pop();
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}