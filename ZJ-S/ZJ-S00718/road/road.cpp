#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[10015],cnt,ans;
struct node{
	int from,to,val;
}a[2000005];
bool cmp(node x,node y){
	return x.val<y.val;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>a[i].from>>a[i].to>>a[i].val;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++) cin>>x;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int ff=find(a[i].from),ft=find(a[i].to);
		if(ff!=ft){
			fa[ff]=ft;
			cnt++;
			ans+=a[i].val;
		}
		if(cnt==n-1) break;
	}
	cout<<ans<<'\n';
	return 0;
}
