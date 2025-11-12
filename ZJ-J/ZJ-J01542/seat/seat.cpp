#include<bits/stdc++.h>
using namespace std;
long long m,n,a;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	long long num=0;
	for(int i=2;i<=n*m;i++)
	{
		long long x;
		cin>>x;
		if(x>=a)
		{
			num++;
		}
	}
	int i=1,j=1;
	for(int k=1;k<=num;k++)
	{
		if((i==n && j%2==1) || (i==1 && j%2==0))
		{
			j++;
		}
		else
		{
			if(j%2==1)
			{
				i++;
			}
			else
			{
				i--;
			}
		}
	}
	cout<<j<<" "<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
