#include<iostream>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,i,j=0,k,c[505];
	long long ans;
	string s;
	cin>>n>>m>>s;
	ans=1;
	k=0;
	for(i=1;i<=n;i++)
	{
		cin>>c[i]; 
		if(c[i]!=0)
		{
			k++;
		}
		else
		{
			j++;
		}
	}
	for(;k>=1;k--)
	{
		ans=(ans*k)%998244353;
	}
	if(j==0)
	{
		cout<<ans;
	}
	else
	{
		cout<<ans*j%998244353;
	}
	return 0;
}
