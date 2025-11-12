#include<bits/stdc++.h>
using namespace std;
int sum,a,b,tong[105][105],p;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			cin>>tong[i][j];
			p=tong[0][0];
			if(tong[i][j]>p)
			{
				sum++;
			}
		}
	}
	cout<<sum/b+1<<" ";
	if((sum/b)%2==0)
	{
		cout<<sum%b+1;
	}
	else
	{
		cout<<b-sum%b;
	}
	return 0;
}//100 95 94
// 99  96
// 98  97