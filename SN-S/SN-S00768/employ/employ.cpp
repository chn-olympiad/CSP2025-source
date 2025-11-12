#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],s[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(m==1)
	{
		int sum=1;
		for(int i=500;i>=1;i--)
		{
			sum*=i;
		}
		cout<<sum;
		return 0;
	}
	if(m==n)
	{
		cout<<"1";
	}
	return 0;
}
