#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a[5005],dp[5005][10050]; 
ll ans,sum,maxn;
ll getnumof1(ll x){
	ll ans;
	while(x>0){
		ans++;
		x-=(x&(-x));
	}
	return ans;
}
ll ksm(ll di,ll ci){
	if(ci==0)return 1;
	if(ci==1)return di;
	return ksm(di*di%998244353,ci/2)*(ci%2==1?di:1)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
dp[0][0]=1;
sum=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2*a[n]+5;j++){
			dp[i][j]=dp[i-1][j]%998244353;
			if(j-a[i]>0){
				dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%998244353;
			}
			else{
				dp[i][j]=(dp[i][j]+sum)%998244353;
			}
		}
		sum=sum*2%998244353;
		ans=(ans+dp[i-1][a[i]+1]%998244353)%998244353;
	}
	
	cout<<ans;
	return 0;
}
//猜测复杂度为O(n*maxa)
//像是DP
//暴力给了40
//先写暴力 
//可以排序 
//坑：(1<<(i-1))会爆炸,快速幂时间复杂度爆炸，要用递推 
//巴尔泽布，我已登神 
//复杂度O(n*maxa) 
//114514
//freeopen
//feropen
//我想进迷惑行为大赏
//mian()
// #include<bits\stdc++.h>
//1145141919810
//1000000007
