#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,a[N][5],cnt,ans;
void dfs(int step,int res,int cnt1,int cnt2,int cnt3)
{
	if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return ;
	if(step==n+1){
		ans=max(ans,res);
		return ;
	}
	dfs(step+1,a[step][1]+res,cnt1+1,cnt2,cnt3);
	dfs(step+1,a[step][2]+res,cnt1,cnt2+1,cnt3);
	dfs(step+1,a[step][3]+res,cnt1,cnt2,cnt3+1);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		
	}
	
//	sort(a+1,a+n+1,cmp);
//	/*
//	for(int i=1;i<=n;i++)
//		printf("%lld %lld %lld\n",a[i].x,a[i].y,a[i].z);
//	*/
	ans=0;
	dfs(1,0,0,0,0);
	printf("%lld\n",ans);		
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%lld",&T);
	while(T--){
		solve ();
	}
	return 0;
}

