#include<bits/stdc++.h>
#define endl "\n"
#define f(n) for(int i=1;i<=n;i++)
#define IOS cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
using namespace std;
int n,m,k,p,inu,inv,inw[10005];
long long ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	IOS;cin>>n>>m>>k;
	f(m)cin>>inu>>inv>>inw[i];
	sort(inw+1,inw+m+1);
	f(n-1)ans+=inw[i];
	cout<<ans;
	return 0;
}
