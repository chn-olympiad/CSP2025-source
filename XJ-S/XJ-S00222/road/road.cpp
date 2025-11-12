#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m,k,ans;
struct cnm{
	int u,v,w;
}a[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w,ans+=a[i].w;
	cout<<ans;
	return 0;
}
