#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,f[2000009],cnt,ans,tot,c[19],a[1009][19];
struct node{
	int u,v,w;
}s[2000009];
bool cmp(node a,node b){
	return a.w < b.w;
}
int ff(int x){
	return f[x] == x ? x : f[x] = ff(f[x]);
}//SD-J02446上午加的rp到哪里去了？ 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> s[i].u >> s[i].v >> s[i].w;
	}
	for(int i = 1;i <= n + k;i++){
		f[i] = i;
	}
	if(k == 0){
		sort(s + 1,s + m + 1,cmp);
		for(int i = 1;i <= m;i++){
			if(cnt == n - 1){
				break;
			}
			if(ff(s[i].u) != ff(s[i].v)){
				f[ff(s[i].u)] = ff(s[i].v);
				ans += s[i].w,cnt++;
			}
		}
		cout << ans;
		return 0;
	}
	tot = m;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[j][i];
			if(a[j][i] == 0){
				if(ff(i + n) != ff(j)){
					f[ff(i + n)] = ff(j);
					cnt++;
				}
			}
			else{
				s[++tot].u = i + n,s[tot].v = j,s[tot].w = a[j][i];
			}
		}
	}
		sort(s + 1,s + tot + 1,cmp);
		for(int i = 1;i <= tot;i++){
			if(cnt == n + k - 1){
				break;
			}
			if(ff(s[i].u) != ff(s[i].v)){
				f[ff(s[i].u)] = ff(s[i].v);
				ans += s[i].w,cnt++;
			}
		}
		cout << ans;
	return 0;
}
