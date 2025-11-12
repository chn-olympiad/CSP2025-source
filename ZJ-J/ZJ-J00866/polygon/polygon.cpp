#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define endl '\n'
const int N=5005;
int n,a[N];
const long long MOD=998244353;
long long Pow(long long x,int y){
	long long res=1;
	while(y){
		if(y&1)(res*=x)%=MOD;
		y>>=1;(x*=x)%=MOD;
	}
	return res;
}
long long num[N];
long long dp[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	IOS;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	long long res=Pow(2ll,n);
	res=(res-1ll+MOD)%MOD;
	res=(res-(n*1ll)+MOD)%MOD;
	res=(res-((n*1ll)*((n*1ll)-1ll)/2ll)%MOD+MOD)%MOD;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=a[i];++j){
			(dp[i]+=num[j])%=MOD;
		}
		for(int j=5000;j>=0;--j){
			if(j+a[i]<=5000)(num[j+a[i]]+=num[j])%=MOD;
		}
		for(int j=1;j<i;++j){
			if(a[j]+a[i]<=5000)++num[a[i]+a[j]],num[a[i]+a[j]]%=MOD;
		}
	}
	for(int i=1;i<=n;++i)res=(res-dp[i]+MOD)%MOD;
	cout<<res<<endl;
	return 0;
}
//9:58 xie wan le
//gan jue hen jian dan
//neng AK ba
//dui pai xie hao le
//liang ge xiao shi hao wu liao
//guan zhu 1040109 & 1137860 ~