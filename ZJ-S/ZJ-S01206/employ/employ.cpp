#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fi first
#define se second
#define endl '\n'
#define start_multitest\
	int tests;\
	cin>>tests;\
	for(int test_case=1;test_case<=tests;test_case++)[&]()->int\
	{
#define end_multitest\
		return 0;\
	}();
constexpr unsigned int mod=998244353;
int n,m;
bool S[510];
int C[510];
int DP[(1<<18)+10][20];
int ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		S[i]=(ch=='1');
	}
	for(int i=1;i<=n;i++)cin>>C[i];
//	bool flag=1;
//	for(int i=1;i<=n;i++)flag&=(S[i]==1);
//	if(flag)
//	{
//		int cnt=0;
//		for(int i=1;i<=n;i++)if(!C[i])cnt++;
//		return 0;
//	}
	DP[0][0]=1;
	for(int i=0;i<1<<n;i++)
	{
		int ppcnt=__builtin_popcount(i);
		for(int j=0;j<=ppcnt;j++)
			for(int k=1;k<=n;k++)
				if(!(i>>(k-1)&1))
				{
					if(!S[ppcnt+1])(DP[i|(1<<(k-1))][j]+=DP[i][j])%=mod;
					else if(ppcnt-j>=C[k])(DP[i|(1<<(k-1))][j]+=DP[i][j])%=mod;
					else (DP[i|(1<<(k-1))][j+1]+=DP[i][j])%=mod;
				}
	}
	for(int i=m;i<=n;i++)
		(ans+=DP[(1<<n)-1][i])%=mod;
	cout<<ans;
	return 0;
}