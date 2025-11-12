#include<bits/stdc++.h>
using namespace std;

const long long w = 1e18;
int n, m, k, l, u[1000011], v[1000011], d[1000011], c[101], a[101][10011];
pair<long long, int> num[1021][1021], f[5000001];
bool ok[1001];

int main(){
	freopen("road.in",  "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0;i <= 1020;i++){
		for(int j = 0;j <= 1020;j++){
			num[i][j].first = w;
		}
	}
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d", &u[i], &v[i], &d[i]);
		num[min(u[i], v[i])][max(v[i], u[i])].first = d[i];
	}
	if(k == 0){
		sort(d + 1, d + m + 1);
		long long ans = 0;
		for(int i = 1;i < n;i++){
			ans += d[i];
		}
		printf("%lld\n", ans);
		return 0;
	}
	for(int i = 1;i <= k;i++){
		scanf("%d", &c[i]);
		for(int j = 1;j <= n;j++){
			scanf("%d", &a[i][j]);
		}
		for(int j = 1;j <= n;j++){
			num[j][n + i].first = a[i][j];
			num[j][n + i].second = i;
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(num[i][j].first != w){
				f[++l].first = num[i][j].first;
				f[l].second = num[i][j].second;
			}
		}
	}
	sort(f + 1, f + l + 1);
	long long ans = 0;
	for(int i = 1;i < n;i++){
		ans += f[i].first;
		if(!ok[f[i].second]){
			ok[f[i].second] = 1;
			ans += c[f[i].second];
		}
	}
	printf("%lld", ans);
}
