#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c,ans,h;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		ans+=c;
	}
	for(int i=1;i<=k;i++){
		h=0;
		for(int j=1;j<=n+1;j++){
			cin>>a;
			h+=a;
		}
		ans=min(ans,h);
	}
	cout<<ans;
	return 0;
}