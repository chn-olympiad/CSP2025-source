#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
long long t, n, m, a[N][4], c[N], num, l, ma;
struct node{
	int a1, b1, c1, n1;
} f[N];
bool cmp(const node& x, const node& y){
	return x.a1 > y.a1;
}
bool cmp2(const node& x, const node& y){
	return x.b1 > y.b1;
}
bool cmp3(const node& x, const node& y){
	return x.c1 > y.c1;
}
void bfs(int s)
{
	int i; l = 0;
	for(i = 1; i <= n; i ++){
		if(c[i] == s){
			l ++;
			f[l].a1 = a[i][1];
			f[l].b1 = a[i][2];
			f[l].c1 = a[i][3];
			f[l].n1 = i;
		}
	}
}
void dfss(int k1, int k2, int k3, long long s, long long cnt)
{
	if(s >= n && k1 + k2 + k3 == n){
		ma = max(ma, cnt);
	}
	if(k1 < m) dfss(k1 + 1, k2, k3, s + 1, cnt + a[s][1]);
	if(k2 < m) dfss(k1, k2 + 1, k3, s + 1, cnt + a[s][2]);
	if(k3 < m) dfss(k1, k2, k3 + 1, s + 1, cnt + a[s][3]);
}
void dfs2(int k1, int k2, long long s, long long cnt)
{
	if(s >= n){
		ma = max(ma, cnt);
	}
	if(k1 < m) dfs2(k1 + 1, k2, s + 1, cnt + a[s][1]);
	if(k2 < m) dfs2(k1, k2 + 1, s + 1, cnt + a[s][2]);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	int i, k1, k2, k3, ok;
	while(t --){
		scanf("%d", &n); m = n / 2;
		k1 = k2 = k3 = num = l = ma = ok = 0;
		for(i = 1; i <= n; i ++){
			scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
			if(a[i][3] != 0) ok = 1;
			if(a[i][1] > a[i][2]){
				if(a[i][1] > a[i][3]){
					num += a[i][1];
					c[i] = 1; k1 ++;
				}
				else{
					num += a[i][3];
					c[i] = 3; k3 ++;
				}
			}
			else{
				if(a[i][2] > a[i][3]){
					num += a[i][2];
					c[i] = 2; k2 ++;
				}
				else{
					num += a[i][3];
					c[i] = 3; k3 ++;
				}
			}
		}
		if(n >= 30){
			if(k1 <= m && k2 <= m && k3 <= m){
				printf("%lld\n", num);
				continue;
			}
			if(!ok){
				dfs2(0, 0, 1, 0);
				printf("%lld\n", ma);
				continue;
			}
			if(k1 > m){
				bfs(1);
				sort(f + 1, f + l + 1, cmp);
				for(i = m + 1; i <= l; i ++){
					num -= f[i].a1;
					if(f[i].b1 < f[i].c1) num += f[i].c1, k3 ++;
					else num += f[i].b1, k2 ++;
				}
				if(k2 <= m){
					if(k3 > m){
						bfs(3);
						sort(f + 1, f + l + 1, cmp3);
						for(i = m + 1; i <= l; i ++){
							num -= f[i].c1;
							num += f[i].b1;
						}
					}
				}
				else{
					bfs(2);
					sort(f + 1, f + l + 1, cmp2);
					for(i = m + 1; i <= l; i ++){
						num -= f[i].b1;
						num += f[i].c1;
					}
				}
			}
			else if(k2 > m){
				bfs(2);
				sort(f + 1, f + l + 1, cmp2);
				for(i = m + 1; i <= l; i ++){
					num -= f[i].b1;
					if(f[i].a1 < f[i].c1) num += f[i].c1, k1 ++;
					else num += f[i].a1, k3 ++;
				}
				if(k1 <= m){
					if(k3 > m){
						bfs(3);
						sort(f + 1, f + l + 1, cmp3);
						for(i = m + 1; i <= l; i ++){
							num -= f[i].c1;
							num += f[i].a1;
						}
					}
				}
				else{
					bfs(1);
					sort(f + 1, f + l + 1, cmp);
					for(i = m + 1; i <= l; i ++){
						num -= f[i].a1;
						num += f[i].c1;
					}
				}
			}
			else{
				bfs(3);
				sort(f + 1, f + l + 1, cmp3);
				for(i = m + 1; i <= l; i ++){
					num -= f[i].c1;
					if(f[i].a1 < f[i].b1) num += f[i].b1, k2 ++;
					else num += f[i].a1, k1 ++;
				}
				if(k1 <= m){
					if(k2 > m){
						bfs(2);
						sort(f + 1, f + l + 1, cmp2);
						for(i = m + 1; i <= l; i ++){
							num -= f[i].b1;
							num += f[i].a1;
						}
					}
				}
				else{
					bfs(1);
					sort(f + 1, f + l + 1, cmp);
					for(i = m + 1; i <= l; i ++){
						num -= f[i].a1;
						num += f[i].b1;
					}
				}
			}
			printf("%lld\n", num);
		}
		else{
			ma = 0; dfss(0, 0, 0, 1, 0);
			printf("%lld\n", ma);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
