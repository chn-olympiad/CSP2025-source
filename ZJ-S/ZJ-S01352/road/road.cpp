#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,sum,ans,f[100010],c[100],b[100][10010];
bool flag;
struct node{
	int u,v,w;
}a[2000010];
bool cmp(node i,node j){
	return i.w<j.w;
}
int getfa(int x){
	return f[x]==x?x:f[x]=getfa(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++) cin>>b[i][j];
	}
	if(flag==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				a[++m].u=n+i;
				a[m].v=j;
				a[m].w=b[i][j];
			}
		}
		for(int i=1;i<=n+k;i++) f[i]=i;
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			int fx=getfa(a[i].u),fy=getfa(a[i].v);
			if(fx!=fy){
				f[fx]=fy;
				sum++;
				ans+=a[i].w;
			}
			if(sum==n+k-1) break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fx=getfa(a[i].u),fy=getfa(a[i].v);
		if(fx!=fy){
			f[fx]=fy;
			sum++;
			ans+=a[i].w;
		}
		if(sum==n-1) break;
	}
	cout<<ans;
	return 0;
}
