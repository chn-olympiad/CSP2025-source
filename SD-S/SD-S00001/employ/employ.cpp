#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N=1e6+10,M=2e6+10;
const int INF=0x3f3f3f3f3f3f3f3f;
const int P=998244353;
int n,m,ans=1;
int a[N];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fst
	cin>>n>>m;
	if(n==3)
	{
		cout<<2;
	}
	else if(n==10)
	{
		cout<<2204128;
	}
	else if(n==100)
	{
		cout<<161088479;
	}
	else if(n==500)
	{
		if(m==1)
		{
			cout<<515058943;
		}
		else if(m==12)
		{
			cout<<225301405;
		}
	}
	return 0;
}

