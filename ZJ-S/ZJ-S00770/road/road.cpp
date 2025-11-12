//long long
#include<bits/stdc++.h>
using namespace std;
const long long N=2e4+5,M=3e6+5,K=15;
struct cyc{
	long long v,w;
	bool operator <(const cyc c)const{
		return w>c.w;
	} 
}; 
long long Cnt,Head[N],Next[M],Go[M],W[M],c[K];
void Add(long long u,long long v,long long w){
	Next[++Cnt]=Head[u];
	Head[u]=Cnt;
	Go[Cnt]=v,W[Cnt]=w;
}
long long n,m,k,ans;
bool vis[N];
long long Kr(long long u){
	long long sum=0,p=0;
	memset(vis,0,sizeof vis);
	for(long long i=0;i<k;i++){
		if(u&(1<<i))sum+=c[i+1],p++;
		else vis[n+i+1]=1;
	}
	priority_queue<cyc> E;
	vis[1]=1;
	for(long long i=Head[1];i;i=Next[i]){
		E.push({Go[i],W[i]});
	}
	for(long long j=1;j<n+p;j++){
		cyc to=E.top();
		E.pop();
		while(vis[to.v]){
			to=E.top();
			E.pop();
		}
		vis[to.v]=1;
		sum+=to.w;
		for(long long i=Head[to.v];i;i=Next[i]){
	    	if(!vis[Go[i]])E.push({Go[i],W[i]});
    	}
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		Add(u,v,w),Add(v,u,w);
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			long long w;
			cin>>w;
			Add(n+i,j,w),Add(j,n+i,w);
		}
	}
	long long duoyu=0;
	ans=Kr(0);
	for(long long i=1;i<=k;i++){
		long long sum=Kr(1<<(i-1));
		if(sum>=ans)duoyu|=1<<(i-1);
	}
	for(long long i=1;i<(1<<k);i++){
		if((i&duoyu)==0)ans=min(ans,Kr(i));
	}
	cout<<ans;
	return 0;
}
/*
城市化第j个村，还不如不城市化，则当该村与其他村共同城市化时会显得更加多余 
*/
