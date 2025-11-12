#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5010;
int a[N];
int calc(int x,int y){
	int res=1;
	for(int i=x;i>=x-y+1;i--) res*=i;
	for(int i=1;i<=y;i++) res/=i;
	res%=mod;
	return res; 
}
int sum=0;
void dfs(int k,int l,int cnt){
	if(k<0&&cnt>=3){
		sum++;
		sum%=mod;
	}
	for(int i=l-1;i>=1;i--)
		dfs(k-a[i],i,cnt+1);
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,f=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<"1";
		else cout<<"0";
		return 0;
	}
	if(a[1]==a[n]&&a[1]==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=calc(n,i);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	for(int i=n;i>=3;i--) dfs(a[i],i,1);
	cout<<sum%mod;
	return 0;
}
