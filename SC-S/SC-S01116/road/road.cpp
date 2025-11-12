#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,p=1;
	char ch=getchar();
	while(ch<'0' or ch>'9'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*p;
}
struct Edge{
	int u,v,w;
	bool operator>(const Edge x)const{
		return w>x.w;
	}
};
priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
int fa[10010];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		pq.push({u,v,w});
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	int q=0,ans=0;
	while(q<n-1){
		Edge s=pq.top();pq.pop();
		if(find(s.u)!=find(s.v)){
			fa[find(s.u)]=find(s.v);
			ans+=s.w;
			q++;
		}
	}
	cout<<ans;	
	return 0;
}