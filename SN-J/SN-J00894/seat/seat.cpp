#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],ansq,answ;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int nb=a[1];
	sort(a+1,a+1+n*m);
	int r=n*m;
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[r]==nb)
				{
					ansq=i;
					answ=j;	
					break;
				}
				r--;		
			}	
		}
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				if(a[r]==nb)
				{
					ansq=i;
					answ=j;	
					break;
				}
				r--;		
			}	
		}
		if(ansq!=0)break;
	}
	cout<<ansq<<" "<<answ;
	return 0;
}
