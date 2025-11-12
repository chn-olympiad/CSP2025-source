#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M=15;
int T,n,a[M];
priority_queue<int,vector<int>,greater<int>>q[3];
inline void solve(){
	int ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		int mx,mi;
		for(int j=0;j<3;++j)
			scanf("%lld",&a[j]);
		if(a[0]>a[1])mx=0,mi=1;
		else mx=1,mi=0;
		if(a[2]>a[mx])mi=mx,mx=2;
		else if(a[2]>a[mi])mi=2;
		q[mx].emplace(a[mx]-a[mi]);
		ans+=a[mx];
	}
	int mx=0,m=n>>1;
	for(int i=1;i<3;++i)
		if(q[i].size()>q[mx].size())mx=i;
	
	while(q[mx].size()>m)
		ans-=q[mx].top(),q[mx].pop();
	printf("%lld\n",ans);
	for(int i=0;i<3;++i)
		while(q[i].size())q[i].pop();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)solve();
	return 0;
}
// Intel Core(TM)2 Duo E7500
// 14:40 AC club5.in/out
// 5*1e5 nlogn 1.752s (?