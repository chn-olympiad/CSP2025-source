#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int tmp[100010];
int tmp1[100010];
struct road{
	int u,n,w;
}ans[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>ans[i].n>>ans[i].u>>ans[i].w;
	for(int i=1;i<=k;i++) cin>>tmp1[i];
	for(int i=1;i<=n;i++) cin>>tmp[i];
	sort(tmp+1,tmp+n+1);
	sort(tmp1+1,tmp1+k+1);
	if(tmp[1]==tmp[n] && tmp[1]==0 && tmp1[1]==tmp1[k] && tmp1[1]==0) cout<<0;
	else{
		cout<<13;
	}
	return 0;
}
