#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
int n,a,b,c,g[10000006][10000006];
signed main(){
	FI("road");
	FO("road");
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		g[a][b]=c;
		sum+=c;
	}
	cout<<sum;
	return 0;
}

