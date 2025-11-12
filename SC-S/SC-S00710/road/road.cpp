#include<bits/stdc++.h>
using namespace std;
long long n,m,m1,k;
struct edge{
	long long u,v,w,id;
}e[2000010];
long long fa[20010];
long long find(long long u){
	if(fa[u]!=u) return fa[u]=find(fa[u]);
	return u;
}
bool merge(long long u,long long v){
	u=find(u),v=find(v);
	if(u==v) return 0;
	fa[u]=fa[v];
	return 1;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
bool cmp1(edge a,edge b){
	return a.id<b.id;
}
long long kus(){
	long long ans=0;
	sort(e+1,e+1+m,cmp);
	for(long long i=1;i<=n;i++) fa[i]=i;
	for(long long i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)==1){
			ans+=e[i].w;
		}
	}
	sort(e+1,e+1+m,cmp1);
	return ans;
}
long long kus1(){
	long long ans=0;
	sort(e+1,e+1+m+n,cmp);
	for(long long i=1;i<=n+1;i++) fa[i]=i;
	for(long long i=1;i<=m+n;i++){
		if(merge(e[i].u,e[i].v)==1){
			ans+=e[i].w;
		}
	}
	sort(e+1,e+1+m+n,cmp1);
	return ans;
}
long long c[20],a[20][1010];
map<pair<long long,long long>,long long> ma;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m1>>k;
	m=1;
	for(long long i=1;i<=m1;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		if(ma[{u,v}]==0){
			ma[{u,v}]=m;
			e[m]={u,v,w,m};
			m++;
		}
		else{
			e[ma[{u,v}]].w=min(e[ma[{u,v}]].w,w);
		}
	}
	m--;
	if(k==0){
		cout<<kus();
	}
	else{
		for(long long i=1;i<=k;i++){
			bool flag=0;
			cin>>c[i];
			if(c[i]!=0) flag=1;
			for(long long j=1;j<=n;j++){
				cin>>a[i][j];
				if(a[i][j]!=0) flag=1;
			}
			if(flag==0){
				cout<<0,exit(0);
				break;
			}
		}
		long long ans=kus();
		for(long long i=1;i<=k;i++){
			for(long long j=1;j<=n;j++){
				e[m+j]={j,n+1,a[i][j],m+j+114};
			}
			cout<<kus1()<<" "<<c[i]<<" "<<kus1()+c[i]<<"\n";
			ans=min(ans,kus1()+c[i]);
		}
		cout<<ans;
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

*/