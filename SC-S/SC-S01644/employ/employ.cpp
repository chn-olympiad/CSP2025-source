#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[1000006];
string S;
int mem[(1<<18)+6][20][20];
int P[1000006];
int dfs(int s,int k,int t,int sn)
{
	if(t==0)return P[sn];
	if(s==0)return 0;
	if(mem[s][k][t])return mem[s][k][t];
	int res=0;
	for(int i=0;i<n;i++)
	{
		if((s>>i)&1==1)
		{
			if(k>=c[i]||S[n-sn]=='0')res+=dfs(s^(1<<i),k+1,t,sn-1);
			else res+=dfs(s^(1<<i),k,t-1,sn-1);
		}
	}
	return res;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	P[0]=1;
	for(int i=1;i<=100;i++)P[i]=P[i-1]*i%mod;
	cin>>n>>m;
	cin>>S;
	for(int i=0;i<n;i++)cin>>c[i];
	cout<<dfs((1<<n)-1,0,m,n);
	
	return 0;
}