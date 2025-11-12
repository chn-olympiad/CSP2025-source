#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long u,v,w;
	friend bool operator <(edge a,edge b){
		return a.w>b.w;
	}
};
priority_queue <edge> q;
long long f[100005];
long long n,m,k,u1,v1,w1,ans;
long long find(long long x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void query(long long a,long long b){
	f[a]=f[b];
	return ;
}
void make(){
	for(int i=1;i<=n;i++) f[i]=i;
}
long long mt(){
	edge now;
	long long add=0,ans=0;
	while(add<n-1){
		now=q.top();
		q.pop();
		if(f[now.u]==f[now.v]) continue;
		else{
			query(now.u,now.v);
			ans+=now.w;
			add++;
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	if(k==0){
		for(int i=1;i<=m;i++){
			scanf("%lld%lld%lld",&u1,&v1,&w1);
			ans+=w1;
			q.push({u1,v1,w1});
		}
		make();
		printf("%lld",mt());
	}
	else printf("%lld",ans);
	return 0;
}
