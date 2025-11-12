#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct node{
	int u,v,w;
}a[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int f[N],sz[N],n,m,k,c[20],d[20][N],ans=0,maxw;
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
vector<int> g[N];
signed main(){
	//15:42 start  666 才16pts 太气人了qwq 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		
	}
	
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		int ru=find(u),rv=find(v);
		if(ru!=rv){
			if(sz[ru]>sz[rv])swap(ru,rv);
			g[rv].push_back(ru);
			f[ru]=rv;
			sz[rv]+=sz[ru];
			sz[ru]=0;
			ans+=w;
			cnt++;
			if(cnt==n-1)maxw=w;
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	return 0;
}

