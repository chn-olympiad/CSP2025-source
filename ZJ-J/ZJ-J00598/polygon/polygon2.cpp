#include<bits/stdc++.h>
using namespace std;
int a[5005],sum;
unordered_map<int,int>mp[5005];
const long long mod=998244353;
int solve(int i,int j){
	if(j<0||j>sum)return 0;
	if(i==0){
		if(j==0)return 1;
		return 0;
	}
	if(mp[i].find(j)!=mp[i].end())return mp[i][j];
	return mp[i][j]=(long long)(solve(i-1,j)+solve(i-1,j-a[i])+solve(i,j+1))%mod;
}
int main(){
	freopen("polygon1.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		(ans+=solve(i-1,a[i]+1))%=mod;
		sum+=a[i];
	}
	cout<<ans<<'\n';
	return 0;
}
//10:17 380pts sleep!
//10:21 wake up(?)
