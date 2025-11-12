#include<bits/stdc++.h>
using namespace std;
long long ans = 0,fa[10005],anss = 1e9;
struct node{
	long long u,v,w;
}b[1000005],bb[2000005];
bool cmp(node a,node c){
	return a.w < c.w;
}
long long find(long long wyr){
	if(fa[wyr] == wyr) return wyr;
	else{
		long long wyrd = find(fa[wyr]);
		fa[wyr] = wyrd;
		return wyrd;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long n,m,k,t = 0;
	cin >> n >> m >> k;
	for(long long i = 1;i <= n;i++) fa[i] = i;
	for(long long i = 1;i <= m;i++){
		cin >> b[i].u >> b[i].v >> b[i].w;
	}
	sort(b+1,b+n+1,cmp);
	for(long long i = 1;i <= m;i++){
		long long uu = b[i].u;
		long long vv = b[i].v;
		long long uf = find(uu);
		long long vf = find(vv);
		if(uf == vf) continue;
		else{
			fa[uf] = vf;
			ans += b[i].w;
			t++;
			if(t == n-1) break;
		}
	}
	anss = ans;
	while(k--){
		long long pi;
		t = 0;
		ans = 0;
		cin >> pi;
		for(long long i = 1;i <= n+1;i++) fa[i] = i;
		for(long long i = 1;i <= m;i++){
			bb[i].u = b[i].u;
			bb[i].v = b[i].v;
			bb[i].w = b[i].w;
		}
		for(long long i = 1;i <= n;i++){
			long long wei;
			cin >> wei;
			bb[m+i].u = i;
			bb[m+i].v = n+1;
			bb[m+i].w = wei;
		}
		sort(bb+1,bb+m+n+1,cmp);
		for(long long i = 1;i <= m+n;i++){
			long long uu = bb[i].u;
			long long vv = bb[i].v;
			long long uf = find(uu);
			long long vf = find(vv);
			if(uf == vf) continue;
			else{
				fa[uf] = vf;
				ans += bb[i].w;
				t++;
				if(t == n) break;
			}
		}
		anss = min(ans+pi,anss);
	}
	cout << anss << endl;
	return 0;
}

