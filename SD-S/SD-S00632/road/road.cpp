#include<bits/stdc++.h>
struct S{
	int u,v,w;
};
using namespace std;
const int N=1e4+5;
int n,m,k,c[N],q[15][N],f=0,p[N];
vector<S>g;
int find(int x){
	if(p[x]!=x)p[x]=find(p[x]);
	return p[x];
}
void merge(int a,int b){
	int pa=find(a),pb=find(b);
	if(pa!=pb)p[pa]=pb;
}
bool same(int a,int b){
	int pa=find(a),pb=find(b);
	return pa==pb;
}
bool cmp(S a,S b){
	return a.w<b.w;
}
int kurscal(){
	long long res=0;
	int cnt=1;
	for(S t:g){
		int u=t.u,v=t.v,w=t.w;
		if(same(u,v))continue;
		cnt++,res+=w;
		merge(u,v);
		if(cnt==n)return res;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g.push_back({u,v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>q[i][j];
	}
	cout<<kurscal();
	return 0;
}

