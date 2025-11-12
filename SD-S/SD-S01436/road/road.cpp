#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10,M = 1e6 + 10,K = 15; 
int n,m,k;
int c[K],f[N + K],e[K][N],tot[K];
struct node{
	int u,v,len;
}a[M];
node t[K][N];
int find(int x){
	if(f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int fun(int x,int y){
	int ans = 1;
	while(y){
		if(y & 1) ans *= x;
		x *= x;
		y >>= 1; 
	}
	return ans;
}
bool cmp(node n1,node n2){
	return n1.len < n2.len;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].len);
	}
	sort(a + 1,a + m + 1,cmp);
	bool r = true;
	for(int i = 1;i <= k;i++){
		scanf("%d",&c[i]);
		if(c[i] > 0) r = false;
		bool check = false;
		for(int j = 1;j <= n;j++){
			scanf("%d",&e[i][j]);
			if(e[i][j] == 0) check = true;
			t[i][j].u = j;
			t[i][j].v = n + i;
			t[i][j].len = e[i][j];
		}
		if(!check) r = false;
		sort(t[i] + 1,t[i] + n + 1,cmp);
	}
	if(k == 0){
		for(int i = 1;i <= n;i++) f[i] = i;
		int sum = 0;
		long long ans = 0;
		for(int i = 1;i <= m;i++){
			int fx = find(a[i].u),fy = find(a[i].v);
			if(fx != fy){
				f[fx] = fy;
				ans += a[i].len;
				sum++;
				if(sum == n - 1){
					printf("%lld",ans);
					return 0;
				}
			}
		}
	}
	if(r){
		for(int i = 1;i <= k;i++){
			int p = 0;
			for(int j = 1;j <= n;j++){
				if(e[i][j] == 0){
					p = j;
					break;
				}
			}
			for(int j = 1;j <= n;j++){
				if(j == p) continue;
				++m;
				a[m].u = p;
				a[m].v = i;
				a[m].len = e[i][j];
			}
		}
		for(int i = 1;i <= n;i++) f[i] = i;
		int sum = 0;
		long long ans = 0;
		for(int i = 1;i <= m;i++){
			int fx = find(a[i].u),fy = find(a[i].v);
			if(fx != fy){
				f[fx] = fy;
				ans += a[i].len;
				sum++;
				if(sum == n - 1){
					printf("%lld",ans);
					return 0;
				}
			}
		}
		return 0;
	} 
	int l = fun(2,k);
	long long ans = 1000000000000000000;
	for(int i = 0;i < l;i++){
		memset(tot,0,sizeof(tot));
		int sum = 0,mlen = 0;
		long long cnt = 0;
		for(int j = 1;j <= k;j++){
			if((i >> (j - 1)) & 1){
				cnt += c[j];
				sum++;
			}
		}
		for(int j = 1;j <= n + k;j++) f[j] = j;
		while(1){
			node mi = {a[tot[0] + 1].u,a[tot[0] + 1].v,a[tot[0] + 1].len};
			int p = 0;
			for(int j = 1;j <= k;j++){
				if((i >> (j - 1)) & 1){
					if(t[j][tot[j] + 1].len < mi.len){
						mi = {t[j][tot[j] + 1].u,t[j][tot[j] + 1].v,t[j][tot[j] + 1].len};
						p = j;
					}
				}
			}
			tot[p]++;
			if(p == 0){
				int fx = find(a[tot[p]].u),fy = find(a[tot[p]].v);
				if(fx != fy){
					f[fx] = fy;
					cnt += a[tot[p]].len;
					mlen++;
					if(mlen == n + sum - 1) break;
				}
			}else{
				int fx = find(t[p][tot[p]].u),fy = find(t[p][tot[p]].v);
				if(fx != fy){
					f[fx] = fy;
					cnt += t[p][tot[p]].len;
					mlen++;
					if(mlen == n + sum - 1) break;
				}
			}
		}
		if(cnt < ans){
			ans = cnt;
		}
	}
	printf("%lld",ans);
	return 0; 
}
