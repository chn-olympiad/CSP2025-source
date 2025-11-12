#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
int n,m,k,u,v,w,c,d,ans,cnt,a[1000005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	IOS
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
		a[cnt++]=w;
	}
	for(int i=0;i<k;i++){
		cin>>c;
		for(int j=0;j<n;j++){
			cin>>d;
		}
	}
	if(n==m){
		cout<<ans;
	}
	else{
		ans=0;
		sort(a,a+cnt);
		for(int i=0;i<n-1;i++){
			ans+=a[i];
		}
		cout<<ans;
	}
	return 0;
}
