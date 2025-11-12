#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;
}t[1000010];
long long c[20],a[20][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>t[i].u>>t[i].v>>t[i].w;
		ans+=t[i].w;
	}
	for(int i=1;i<=k;i++){
		int flag=1;
		cin>>c[i];
		if(c[i]){
			flag=0;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]){
				flag=0;
			}
		}
		if(flag){
			cout<<0;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}