//张巍骞 SN-S00224 曲江第一学校
#include<bits/stdc++.h >
using namespace std;
#define int long long
int n,m,k;
const int N =1e4+10;
int fa[N];
int c[N];
bool f=  false;
struct node {
	int u,v,w;
} a[N];
int find(int k) {
	if(fa[k]!=k) return find(fa[k]);
	return fa[k];
}
int asd = 0;
void kl() {
	int cnt = 1;
	
	for(int i = 1; i<= m; i++) {

		int u1 = a[i].u,v1 = a[i].v,w1 = a[i].w;
		int pu = find(u1),pv = find(v1);
		if(pu!=pv) {
			fa[pu] = pv;
			asd+=w1;
			cnt++;
		}
		if(cnt==n+1) {
			return;
		}


	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i = 1; i<= m; i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
		fa[i] = i;
	}
	for(int i = 1; i<= k; i++) {
		cin>>c[i];
		if(c[i]!=0){
			f = true;
		}
		for(int j = 1; j<= n; j++) {
			a[j+m].u = n+i;
			a[j+m].v = j;
			cin>>a[j+m].w;
			
		}
	}
	kl();
	if(!f){
		cout<<0;
		return 0;
	}
	cout<<asd;
	return 0;
}
