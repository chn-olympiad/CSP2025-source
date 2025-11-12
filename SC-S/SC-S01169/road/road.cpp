#include<bits/stdc++.h>
using namespace std;
long long n, m, k, a[10005][10005], x[10005], y, ans[10005], zans = 1e18, lans, u, v, e;
bool fl[10005], fff[10005];
int ans1[10005], ans2[10005];
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		scanf("%lld %lld %lld", &u, &v, &e);
		a[u][v] = e;
		a[v][u] = e;
	}
	for(int i = 1;i <= k;i++){
		scanf("%lld", &x[i]);
		for(int j = 1;j <= n;j++){
			scanf("%lld", &y);
			a[n + i][j] = y;
			a[j][n + i] = y;
		}
	}
	
	for(int i = 1;i <= n + k;i++){
		lans = 0;
		queue<int> q;
		fill(ans, ans + 1 + n + k, 1e18);
		fill(ans1, ans1 + n + k, 0);
		fill(fl, fl + 1 + n + k, 0);
		fill(fff + 1, fff + 1 + n + k, 0);
		ans[i] = 0;
		q.push(i);
		bool ff = 1;
		while(q.size()){
			int xx = q.front();
			q.pop();
			if(!ff)break;
			for(int j = 1;j <= n + k;j++){
				if(a[xx][j] && ans[xx] + a[xx][j] + (xx > n && !fl[std::max((long long)(xx - n), (long long)(0))]) * x[std::max((long long)(xx - n), (long long)(0))] < ans[j]){
					q.push(j);
					fff[xx] = 1;
					if(ans1[j]){
						fl[ans1[j]] = 0;
						ans1[j] = 0;
					}
					if(ans2[j]){
						fff[ans2[j]] = 0;
						ans2[j] = 0;
					}
					ans[j] = ans[xx] + a[xx][j] + x[std::max((long long)(xx - n), (long long)(0))] * (xx > n && !fl[std::max((long long)(xx - n), (long long)(0))]);
					if(xx > n)fl[std::max((long long)(xx - n), (long long)(0))] = 1, ans1[j] = xx - n;
					else ans2[j] = xx;
				}
			}
		}
		bool flag = 1;
		for(int j = 1;j <= n;j++){
			if(ans[j] == 1e18){
				flag = 0;
				break;
			}
			if(!fff[j]){
				lans += ans[j];
			}
		}
		if(flag)zans = std::min(zans, lans);
	}
	cout << zans;
	return 0;
} 