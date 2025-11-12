#include<bits/stdc++.h>
using namespace std;
int mian()
{										
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,b[12]={};
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		if(b[i]<=1&&b[i]>=9)
		{
			cout<<b[i];
		}
	}
	return 0;
}
