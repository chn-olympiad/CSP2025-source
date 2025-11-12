#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int xiao_min;
	cin>>xiao_min;
	int min_ci=1,temp;
	for (int i=0;i<n*m-1;i++)
	{
		cin>>temp;
		if (temp>xiao_min)
		{
			min_ci++;
		}
	}
	int c=1,r=1;
	temp=1;
	while (temp!=min_ci)
	{
		if (r==1&&c%2==0)
		{
			c++;
			temp++;
		}
		else if(r==n&&c%2==1)
		{
			c++;
			temp++;
		}
		else if(c%2==1)
		{
			for (;r<n;r++)
			{
				if (temp==min_ci)
				{
					break;
				}
				temp++;
			}
		}
		else
		{
			for (;r>1;r--)
			{
				if (temp==min_ci)
				{
					break;
				}
				temp++;
			}
		}
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}