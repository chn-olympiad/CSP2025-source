#include<bits/stdc++.h>
using namespace std;
const int N=1e4+105;
#define ll long long
#define lowbit(x) x&(-x)
int n,m,k;
int qread(){
	int ret=0;
	char c;
	do{
		c=getchar();
	}while(!isdigit(c));
	do{
		ret=ret*10+c-'0';
		c=getchar();
	}while(isdigit(c));
	return ret;
}
struct Edge{
	int u,v,w;
	bool flag;
	bool operator< (const Edge &x)const{
		return w<x.w;
	}
};
int pr[30];
vector<Edge> edge;
int f[N];
int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void merge(int x,int y){
	f[x]=y;
}
void solve1(bool spa){
	ll ans=0x3f3f3f3f3f3f3f3f;
	for(int p=spa?(1<<k)-1:0;p<(1<<k);p++){
		for(int i=1;i<=n+k;i++)f[i]=i;
		int cnt=0,num=0,tmp=p;
		while(tmp)num++,tmp-=lowbit(tmp);
		ll sum=0;
		for(auto e:edge){
			int u=e.u,v=e.v,we=e.w;
			if(e.flag&&(!((p>>(u-n-1))&1)))continue;
			int fu=find(u),fv=find(v);
			if(fu==fv)continue;
			cnt++;
			sum+=we;
			merge(fu,fv);
			if(cnt==n+num-1)break;
		}
		for(int i=0;i<k;i++)if((p>>i)&1)sum+=pr[i+1];
		ans=min(ans,sum);
	}
	printf("%lld",ans);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=qread();m=qread();k=qread();
	for(int i=1;i<=m;i++){
		int u,v,w;u=qread();v=qread();w=qread();
		edge.push_back({u,v,w,0});
	}
	bool spa=1;
	for(int i=1;i<=k;i++){
		pr[i]=qread();
		if(pr[i]!=0)spa=0;
		for(int j=1;j<=n;j++){
			int w;w=qread();
			if(w!=0)spa=0;
			edge.push_back({i+n,j,w,1});
		}
	}
	sort(edge.begin(),edge.end());
	solve1(spa);
	return 0;
}