#include<bits/stdc++.h>
using namespace std;
bool d(int x,int y)
{
	if(x>y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
long long a,b,c[105],e=0,f;
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	cin>>a>>b;
	for(int i=0;i<a*b;i++)
	{
		cin>>c[i];
	}
	f=c[0];
	sort(c,c+a*b,d);
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(c[e]==f)
			{
				if(i%2==0)
				{
					cout<<i<<" "<<a-j+1;
					return 0;
				}
				else
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			e++;
		}
	}
	return 0;
}