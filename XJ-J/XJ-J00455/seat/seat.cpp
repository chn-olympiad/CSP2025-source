#include<bits/stdc++.h>
using namespace std;
int mian()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c;//n=³¤£¬m=¿í 
	cin>>n>>m;
	for(int i=0;i<=n*m;i++)
	{
		cin>>c;
		if(c>n)
		{
			cout<<m+1;
		}
	}
	return 0;
}
