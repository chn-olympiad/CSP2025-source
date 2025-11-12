//考号：SN-J00509 姓名：李兴辰 学校：安康高新技术产业开发区九年制学校
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,k,a[N],dp[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ll t=0;
		for(int j=i;j;j--){
			t^=a[j];
			if(t==k)dp[i]=max(dp[i],dp[j]+1);
			else dp[i]=max(dp[i],dp[j]);
		}
	} 
	cout<<dp[n];//O(n^2)
	return 0;
} 
