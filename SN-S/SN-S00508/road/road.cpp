#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int n,m,k,ans,b[15][10005],v[15],vis[maxn];
struct f{
	int l,r,va;
}a[maxn];
bool cmp(f xx,f yy){
	return xx.va<yy.va;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].l>>a[i].r>>a[i].va;
	for(int i=1;i<=k;i++){
		cin>>v[i];
		for(int j=1;j<=n;j++) cin>>b[i][j];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-1;i++){
		ans+=a[i].va;
	}
	cout<<ans;
	return 0;
}
