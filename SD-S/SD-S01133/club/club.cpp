#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int T, n;
struct node{
	int x, y, z;
	int cha, maxn, mx;
	int f, f1;
}a[N];

bool cmp(node u, node v){
	return u.cha > v.cha;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int cnt[4];
		long long ans = 0;
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		int nn = n/2;
		for(int i = 1; i <= N; i++){
			a[i].maxn = 0;
			a[i].mx = 0;
			a[i].cha = 0;
			a[i].f1 = 0;
			a[i].f = 0;
		}
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
			if(a[i].maxn < a[i].x){
				a[i].maxn = a[i].x;
				a[i].f = 1;
				a[i].f1 = 1;
				if(a[i].y > a[i].z){
					a[i].f1 = 2;
					a[i].mx = a[i].y;
				}
				else{
					a[i].f1 = 3;
					a[i].mx = a[i].z;
				}
			}
			if(a[i].maxn < a[i].y){
				a[i].maxn = a[i].y;
				a[i].f = 2;
				if(a[i].x > a[i].z){
					a[i].f1 = 1;
					a[i].mx = a[i].x;
				}
				else{
					a[i].f1 = 3;
					a[i].mx = a[i].z;
				}
			}
			if(a[i].maxn < a[i].z){
				a[i].maxn = a[i].z;
				a[i].f = 3;
				if(a[i].x > a[i].y){
					a[i].f1 = 1;
					a[i].mx = a[i].x;
				}
				else{
					a[i].f1 = 2;
					a[i].mx = a[i].y;
				}
			}
			a[i].cha = a[i].maxn - a[i].mx;
		}
		
		sort(a + 1, a + 1 + n, cmp);
		for(int i = 1; i <= n; i++){
			if(cnt[a[i].f] < nn){
				cnt[a[i].f]++;
				ans += a[i].maxn;
			}
			else{
				cnt[a[i].f1]++;
				ans += a[i].mx;
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
