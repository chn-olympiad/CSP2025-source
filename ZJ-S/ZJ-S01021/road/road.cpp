#include<bits/stdc++.h>
using namespace std;

const long long N=1e6+10;
const long long M=1e4+10;
long long n,m,k,ans=1e18,num,cnt,flag=1;
long long fa[N];
long long a[15];
long long b[M][12];
struct node{
	long long u,v,w;
	bool friend operator<(node x,node y){
		return x.w<y.w;
	}
}E[N],G[N];

long long find(long long x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void kru(){
	long long cnt=0;
	sort(E+1,E+m+1);
	for(long long i=1;i<=n;i++)
		fa[i]=i;
	for(long long i=1;i<=m;i++){
		long long u=E[i].u;
		long long v=E[i].v;
		if(find(u)==find(v))continue;
		fa[find(u)]=fa[find(v)];
		G[++cnt]={u,v,E[i].w};
	}
}

void kru2(){
	sort(E+1,E+num+1);
	for(long long i=1;i<=n+k;i++)
		fa[i]=i;
	for(long long i=1;i<=num;i++){
		long long u=find(E[i].u);
		long long v=find(E[i].v);
		if(u==v)continue;
		fa[u]=fa[v];
		cnt+=E[i].w;
//		cout<<E[i].u<<' '<<E[i].v<<' '<<E[i].w<<"!\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		E[i]={u,v,w};
	}
	for(long long i=1;i<=k;i++){
		cin>>a[i];
		if(a[i]!=0)flag=0;
		for(long long j=1;j<=n;j++)
			cin>>b[j][i];
	}
	kru();
	if(flag==1){
		cnt=num=0;
		for(long long i=1;i<n;i++)
			E[++num]={G[i].u,G[i].v,G[i].w};
		for(long long j=1;j<=k;j++){
			for(long long l=1;l<=n;l++)
				E[++num]={j+n,l,b[l][j]};
		}
		kru2();
		cout<<cnt;
		return 0;
	}
	for(long long i=0;i<(1<<k);i++){
		cnt=num=0;
		for(long long i=1;i<n;i++)
			E[++num]={G[i].u,G[i].v,G[i].w};
//		cout<<i<<'\n';
		for(long long j=1;j<=k;j++){
			if(((i>>(j-1))&1)==0)continue;
			cnt+=a[j];
			for(long long l=1;l<=n;l++)
				E[++num]={j+n,l,b[l][j]};
		}
//		cout<<cnt<<'\n';
//		for(long long i=1;i<=num;i++)
//			cout<<E[i].u<<" "<<E[i].v<<' '<<E[i].w<<endl;
		kru2();
		ans=min(ans,cnt);
//		cout<<cnt<<'\n';
	}
//	for(long long i=1;i<n;i++)
//		cout<<G[i].u<<' '<<G[i].v<<' '<<G[i].w<<endl;
	cout<<ans;
	return 0;
}

