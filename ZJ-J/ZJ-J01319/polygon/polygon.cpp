#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,i,ans,pos,a[5010];
void dfs(int t,int mg,int he,int ma){
	if(t==n&&mg<3)return ;
	if(t==n&&mg>=3){
		if(he>ma*2)ans++;
		ans=ans%mod;
		return ;
	}
	dfs(t+1,mg,he,ma);
	dfs(t+1,mg+1,he+a[t+1],max(ma,a[t+1]));
}
int c(int zs,int x){
	int i,cnt=1;
	for(i=zs;i>=zs-x+1;zs++)cnt=cnt*i;
	for(i=1;i<=x;i++)cnt=cnt/i;
	return cnt;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],pos=max(pos,a[i]);
	if(pos==1){
		for(i=3;i<=n;i++)ans=(ans+c(n,i))%mod;
		cout<<ans%mod;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans%mod;
}
