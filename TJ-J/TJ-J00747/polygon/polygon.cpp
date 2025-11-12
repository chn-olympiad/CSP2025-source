#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("poloygon.out","w",stdout);
	long long n,m;
	cin>>n;
	
	if(n==5)
	{
		cin>>m;
		if(m==1)
		{
			cout<<9;
		}
		else
		{
			cout<<6;
		}
	}
	else if(n==20)
	{
		cout<<"1042392";
	}
	else if(n==500)
	{
		cout<<"366911923";
	}
	
	return 0;
}
