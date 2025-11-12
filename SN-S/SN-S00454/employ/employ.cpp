//结果T4的25分比T3的B性质好写一亿倍，这下决策成功了 
//注意到-J和-S的T4题目名打乱重组后都有poly子串，暗示NOIP要考多项式（？）
//好吧我错了A性质并不容易 
//好吧我对了2^n是容易的 
//freopen 召唤神兽！ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace kong{bool st;}
namespace zhu{
int n,m,c[550],dp[300300][20];
char s[550];
const int mod=998244353;
int shu(int x){
	int cnt=0;
	for(int i=0;i<n;i++){
		cnt+=(x&(1<<i))?1:0;
	}
	return cnt;
}
string main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))) continue;
			for(int k=0;k<=n;k++){//走的人数 
				if(!dp[i][k]) continue;
				if(s[shu(i)+1]=='0'){
					dp[i|(1<<(j-1))][k+1]=(dp[i|(1<<(j-1))][k+1]+dp[i][k])%mod;
//					cout<<i<<" "<<(i|(1<<(j-1)))<<" "<<j<<" "<<k<<" "<<k+1<<'\n';
				}
				else{
					dp[i|(1<<(j-1))][k+((k>=c[j])?1:0)]=(dp[i|(1<<(j-1))][k+((k>=c[j])?1:0)]+dp[i][k])%mod;
//					cout<<i<<" "<<(i|(1<<(j-1)))<<" "<<j<<" "<<k<<" "<<k+((k>=c[j])?1:0)<<'\n';
				}
			}
		}
//		cout<<bitset<11>(i)<<"\n";
//		for(int j=0;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<'\n';
	}
	int ans=0;
	for(int i=0;i<=n-m;i++){
		ans=(ans+dp[(1<<n)-1][i])%mod;
	}
	cout<<ans<<'\n';
	return "S组只是NOIP的试机赛！";
}
}
namespace kong{bool ed;double MB(){return (&st-&ed)/1048576.0;}}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<kong::MB();
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
