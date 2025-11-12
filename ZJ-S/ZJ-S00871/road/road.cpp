#include<bits/stdc++.h>
using namespace std;
int n, m, k, u[1000010], v[1000010], c[11], a[11][1010];
map<int, map<int, int> > p;
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int w;
		scanf("%d%d%d", &u[i], &v[i], &w);
		if(u[i] > v[i]) swap(u[i], v[i]);
		p[u[i]][v[i]] = min(p[u[i]][v[i]], w);
	}
	bool ok = true;
	for(int i = 1; i <= k; i++){
		scanf("%d", c[i]);
		if(c[i] != 0) ok = false;
		for(int j = 1; j <= n; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j] != 0)
				ok = false;	
		}
	}
	//if(ok){
	//	printf("0\n");
	//	return 0;
	//}
	if(k == 0){
		long long sum = 0;
		for(int i = 1; i < n; i++)
			sum += p[u[i]][v[i]];
		printf("%lld\n", sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
