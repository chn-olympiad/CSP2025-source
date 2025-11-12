#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[10005];
int fn(int a){
	return a==f[a]?a:f[a]=fn(f[a]);
}
struct road{
	int u,v,w;
	void in(){
		cin>>u>>v>>w;
	}
	bool operator<(const road&o)const{
		return w<o.w;
	}
};
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
//	if(k){
//		cout<<0;
//		return 0;
//	}
	for(int i=1;i<=n;i++)f[i]=i;
	vector<road> r(m);
	for(int i=0;i<m;i++){
		r[i].in();
	}
	sort(r.begin(),r.end());
	int an=0;
	for(int i=0;i<m;i++){
		if(fn(r[i].u)==fn(r[i].v))continue;
		f[f[r[i].v]]=f[r[i].u];
		an+=r[i].w;
	}
	cout<<an;
	return 0;
}

