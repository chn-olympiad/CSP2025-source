#include<bits/stdc++.h>
#define int long long
using namespace std;
int m,n,k,w[200005],ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b>>w[i];
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=n-1;i++){
		ans+=w[i];
	}
	cout<<ans<<endl;
}