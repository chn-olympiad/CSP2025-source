#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,k;
long long a[500005];
long long dp[1001][1001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=0;
			dp[i][j]=max(dp[i-1][j-1],dp[i][j-1]);
			for(int q=i;q<=j;q++)
			{
				sum^=a[q];
			}
			if(sum==k)
			{
				dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
			}
//			cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
		}
	}
	long long maxn=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			maxn=max(maxn,dp[i][j]);
		}
	}
	cout<<maxn<<endl;
	return 0;
}
/*
kaishiyuedu 9:15
kaishixie 9:30
(du ti du le shi wu fen zhong,wo shi tian cai ba)
hao xiang zhi hui bao li za ban
you dian xiang zhi qian zuo guo de yi dao ti
dan shi wo wang ji zen me zuo le
T.T
suan le bao li da wan zai shuo
wei sha bu neng yong signed
lai shi wo yi ding bu hui zai yong define int long long le
2^n shi bu shi tai bao zha le(?)
qi shi xing zhi ye mei kan dong you sha yong
wan dan le ba
hao wu si lu
wo shi zui da ju ruo
suan le xian kai T4
wo you hui lai le
wo mei zhao le
n^3 shi shi ba
dp bei yi ge mo ban shi shi
yin wei wo zhen de bu hui
yang li quan guo le?
bie gao su wo zhi neng guo yang li
jieshushijian 11:10
11:44 shi de wo you lai le
qi shi wo zi ji xie de dai ma wo zi ji dou wan quan mei kan dong
chun kao gan jue lai
guo yang li le suan shi wo yun qi hao
dan shi neng bu neng gei wo ji fen
wo yao ku le
T.T
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
zen me ce bu liao a
wo ku le
ok rong xing de cuo le
suan le wo bu guan le
jiao le zai shuo
11:48 le
*/