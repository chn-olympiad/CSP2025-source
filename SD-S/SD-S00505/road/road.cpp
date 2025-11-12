#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e6+5,M=1e4+5;
struct Node{
	int x,y,z;
}a[N];
bool cmp(Node a,Node b){
	return a.z<b.z;
}
int f[M];
int Find(int x){
	if(f[x]==x)return f[x];
	else return f[x]=Find(f[x]);
}
int n,m,k;
int ans=0x7f7f7f7f;
long long dfs(){
	long long ans=0,tot=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int xx=Find(a[i].x);
		int yy=Find(a[i].y);
		if(xx==yy)continue;
		f[xx]=yy;ans+=a[i].z;tot++;
		if(tot==n-1)return ans;
	}
	return -1;
}
signed main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i; 
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	if(k==0){
		long long ans=dfs();
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}


