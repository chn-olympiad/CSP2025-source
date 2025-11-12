#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1||m==n)
	{
		long long res=1;
		for(int i=1;i<=n;i++)
		{
			res*=i;
			res%=998244353;
		}
		cout<<res;
		return 0;
	}
	else
	{
		cout<<0;
	}
}
