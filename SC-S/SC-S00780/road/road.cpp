#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,f[100005],ans,cnt;
int fid(int a){
	if(a!=f[a])
		f[a]=fid(f[a]);
	return f[a];
}
void he(int a,int b){
	a=fid(a),b=fid(b);
	if(a!=b)f[b]=a;
}
struct aaa{
	int u,v,w;
	friend bool operator <(const aaa &a,const aaa &b){
		return a.w<b.w;
	}
}a[1000006];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1,l;i<=k;i++)
		for(int j=1;j<=n+1;j++)cin>>l;
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++){
		if(fid(a[i].u)!=fid(a[i].v)){
			he(a[i].u,a[i].v);
			ans+=a[i].w;
		}
	}
	cout<<ans;
	return 0;
}