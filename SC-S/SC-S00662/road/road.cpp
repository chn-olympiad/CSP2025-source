#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
long long n,m,k,a[19],b[19][N],cnt,ans=INT_MAX;
long long bcj[N*10];
struct edge{
	long long f,t,v;
}e[N*10],w[N*10];
bool cmp(edge x,edge y){return x.v<y.v;}
long long fid(long long x){
	if(bcj[x]==x)return x;
	return bcj[x]=fid(bcj[x]);
}
void buildtree(long long x,long long y){
	for(int i=1;i<=cnt;i++)w[i]=e[i];
	sort(w+1,w+cnt+1,cmp);
	long long cnt1=0,q=0,res=0;
	for(int i=1;i<=x;i++)bcj[i]=i;
//	cout<<x<<" "<<y<<endl;
//	for(int i=1;i<=cnt;i++)cout<<w[i].f<<" "<<w[i].t<<" "<<w[i].v<<endl;
	while(cnt1<x-1&&q<=cnt){
		q++;
		long long fa=fid(w[q].f),fb=fid(w[q].t);
		if(fa!=fb)bcj[fa]=fb,cnt1++,res+=w[q].v;
	}
//	cout<<res+y<<endl;
	if(cnt1==x-1)ans=min(ans,res+y);
	return;
}
void dfs(long long x,long long y,long long z){
	if(x>k){
		buildtree(y,z);
		return;
	}
	dfs(x+1,y,z);
	for(int i=1;i<=n;i++)e[++cnt]={y+1,i,b[x][i]};
	dfs(x+1,y+1,z+a[x]);
	for(int i=1;i<=n;i++)e[--cnt]={0,0,0};
}
int main(){
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].f>>e[i].t>>e[i].v;
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	cnt=m;
	dfs(1,n,0);
	cout<<ans;
	return 0;
}