#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
string a;
const int N=505,mod=998244353;
int n,m,b[N],S,s[N];
bool vis[N];
ll ans,A[N];
void f(int k,int sum)
{
	if(sum>=m)
	{
		ans=(ans+A[n-k+1])%mod;
		return ;
	}
	if(k>n||(n-k+1)-(s[n]-s[k-1])+sum<m)
		return ;
	int i;
	for(i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		vis[i]=1;
		if(a[k]=='1')
		{
			if((b[i]<=S))
			{
				S++;
				f(k+1,sum);
				S--;
			}
			else
			{
				f(k+1,sum+1);
			}
		}
		else
		{
			S++;
			f(k+1,sum);
			S--;
		}
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int j,i;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a;
	a=' '+a;
	A[0]=1;
//	bool flagA=1;
	for(i=1;i<=n;i++)
	{
		s[i]=s[i-1]+(a[i]=='0');
		cin>>b[i];
		A[i]=A[i-1]*i%mod;
//		if(a[i]!='1')
//			flagA=0;
	}
//	if(flagA)
//	{
//		cout<<A[n];
////		j=lower_bound(s+1,s+1+n,1)-s-1;
////		if(j>=m)
////		{
////			cout<<A[n];
////		}
////		else
////			cout<<0;
//	}
//	else
//	{
		f(1,0);
		cout<<ans;
//	}
	return 0;
}
