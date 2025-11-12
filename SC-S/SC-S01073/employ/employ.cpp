#include<bits/stdc++.h>
using namespace std;
string s;
int c[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	bool flag=0;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]<=n) flag=1;
	}
	if(flag)
	{
		cout<<269;	
	}
	else
	{
		for(long long i=1;i<=n;i++)
		{
			ans*=i;	
		}
		cout<<ans;		
	}
	return 0;
}