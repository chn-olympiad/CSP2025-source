#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;
int f[10010];
long long e[10010];
vector<array<long long,3>>a;
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
int merge(int a,int b){
	int fa=find(a);
	int fb=find(b);
	if(fa==fb)return 0;
	f[fb]=fa;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	fre("road");
	long long n,m,k;
	long long ans=0;
	cin>>n>>m>>k;
	iota(f,f+n,0);
	while(m--){
		long long u,v,w;
		cin>>u>>v>>w;
		a.push_back({w,u,v});
	}
	while(k--){
		long long c;
		cin>>c;
		for(int i=1;i<=n;i++){
			long long w;
			cin>>w;
			e[i]=w;
		}
		for(long long i=1;i<n;i++){
			for(long long j=i+1;j<=n;j++){
				a.push_back({e[i]+c+e[j],i,j});
			}
		}
	}
	sort(a.begin(),a.end());
	int l=a.size();
	for(int i=0;i<l;i++){
		if(merge(a[i][1],a[i][2])){
			ans+=a[i][0];
		}
	}
	cout<<ans;
}