#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x, y, z;
}a[1000010], bian[2000010];
int n, m, k, b[20][10010], c[10010], top, fa[10010], f[1010][1010];
const bool cmp(const Node &b1, const Node &b2){
	return b1.z < b2.z;
}
int find(int x){
	if(x == fa[x]){
		return x;
	}
	return fa[x] = find(fa[x]);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1, u, v, h; i <= m; i++){
		scanf("%d%d%d", &u, &v, &h);
		a[i].x = u, a[i].y = v, a[i].z = h;
	}
	for(int i = 1; i <= k; i++){
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++){
			scanf("%d", &b[i][j]);
		}
	}
	if(!k){
		sort(a + 1, a + m + 1, cmp);
		long long A = 0;
		for(int i = 1; i <= n; i++){
			fa[i] = i;
		}
		for(int i = 1; i <= m; i++){
			int fx = find(a[i].x), fy = find(a[i].y);
			if(fx == fy){
				continue;
			}
			fa[fx] = fy;
			A += a[i].z;
		}
		printf("%lld", A);
		return 0;
	}
	long long ans = 1LL << 60, cnt;
	for(int S = 0; S < (1 << k); S++){
		top = 0;
		for(int i = 1; i <= n; i++){
			fa[i] = i;
			for(int j = 1; j <= n; j++){
				f[i][j] = 2e9 + 1;
			}
		}
		for(int i = 1; i <= m; i++){
			f[a[i].x][a[i].y] = f[a[i].y][a[i].x] = a[i].z;
		}
		cnt = 0;
		for(int i = 1; i <= k; i++){
			if((S >> (i - 1)) & 1){
				cnt += c[i];
				for(int j = 1; j <= n; j++){
					for(int l = j + 1; l <= n; l++){
						if(b[i][j] + b[i][l] < f[j][l]){
							f[j][l] = f[l][j] = b[i][j] + b[i][l];
						}
					}
				}
			}
		}
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(f[i][j] != 2e9 + 1){
					top++;
					bian[top].x = i, bian[top].y = j, bian[top].z = f[i][j];
				}
			}
		}
		sort(bian + 1, bian + top + 1, cmp);
		for(int i = 1; i <= top; i++){
			int fx = find(bian[i].x), fy = find(bian[i].y);
			if(fx == fy){
				continue;
			}
			fa[fx] = fy;
			cnt += bian[i].z;
		}
		ans = min(ans, cnt);
	}
	printf("%lld", ans);
	return 0;
}
