#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t1,t2,t3,dp[10000+5][10000+5];
ll ans;
struct node{
	ll a1,a2,a3,maxn;
}a[100000+5];
bool cmpA(node x,node y){return x.a1>y.a1;}
bool cmpB(node x,node y){
	if(x.maxn==y.maxn){
		if(x.a1<x.a2){
			if(y.a1<y.a2){
				return x.a2>y.a2;
			}else{
				return x.a2>y.a1;
			}
		}else{
			if(y.a1<y.a2){
				return x.a1>y.a2;
			}else{
				return x.a1>y.a1;
			}
		}
	}
	return x.maxn>y.maxn;
}
bool cmp1(node x,node y){
	if(x.a1==y.a1){
		if(x.a2==y.a2){
			return x.a3>y.a3;
		}
		return x.a2>y.a2;
	}
	return x.a1>y.a1;
}
inline void solve()
{
	ans=t1=t2=t3=0;
	int teliA=1,teliB=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		a[i].maxn=max(a[i].a1,max(a[i].a2,a[i].a3));
		if(a[i].a2!=a[i].a3||a[i].a2==1||a[i].a3==1)teliA=0;
		if(a[i].a3==1)teliB=0;
	}
	if(teliA){
		sort(a+1,a+n+1,cmpA);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].a1;
		}
		cout<<ans<<'\n';
		return;
	}else if(teliB){
		sort(a+1,a+n+1,cmpB);
		for(int i=1;i<=n;i++){
			if(a[i].a1>a[i].a2){
				if(t1<n/2) ans+=a[i].a1,t1++;
				else ans+=a[i].a2,t2++;
			}else{
				if(t2<n/2) ans+=a[i].a2,t2++;
				else ans+=a[i].a1,t1++;
			}
		}
		cout<<ans<<'\n';
		return;
	}
	sort(a+1,a+n+1,cmp1);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				int xx=dp[i][j];
				if(dp[i-1][k]>xx)dp[i-1][k]+a[i].a1;
				if(dp[i-1][k]>xx)dp[i-1][k]+a[i].a2;
				if(dp[i-1][k]>xx)dp[i-1][k]+a[i].a2;
				dp[i][j]=xx;
			}
		}
	}
	cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<'\n';
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
