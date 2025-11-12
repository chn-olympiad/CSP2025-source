#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[500005],zhuanyi[500005],qzh[500005],n,k,a[500005],lastqwerty[500005]; 
map<ll,ll>pos;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=qzh[i-1]^a[i];
		pos[qzh[i]]=i;
		
		if(pos[(k^qzh[i])]!=0 || (k^qzh[i])==0){
			lastqwerty[i]=pos[k^qzh[i]];
		}else{
			lastqwerty[i]=-1;
			
		}
	}
	for(int i=1;i<=n;i++){
		if(lastqwerty[i]!=-1){
			dp[i]=max(dp[i-1],dp[lastqwerty[i]]+1);
		}
		else{
			dp[i]=dp[i-1];
		}
	}
	cout<<dp[n]<<'\n';
	return 0;
}
//贪心（排序后取最左）是错误的
// 取最短是错误的 
//考虑DP 
//定义dp_i = shiyong i dedaan;在此时取最短焕发新生
//但也不太可行 
//考虑改变dp定义
// 
 

