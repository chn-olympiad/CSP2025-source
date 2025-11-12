//西安高新第二初级中学  姜璟烁  SN-J00237 
#include<bits/stdc++.h>
using namespace std;
int n,l[100000],maxx=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
		maxx=max(maxx,l[i]);
	}
	if(maxx==1)
	{
		cout<<(n-3+1)%998244353;
		return 0;
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if((l[1]+l[2]+l[3])>maxx*2)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	
	return 0;
}
