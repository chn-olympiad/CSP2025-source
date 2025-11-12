#include <bits/stdc++.h>
using namespace std;
long long n,m,a[105],sum;
bool cmp(int g,int h)
{
	return g>h;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sum)
		{
			if(i%n!=0)
			{
				if((i/n+1)%2==1)
				{
					cout << i/n+1 << " " << i%n;
				}
				else
				{
					cout << i/n+1 << " " << (n+1)-(i%n);
				}
			}
			else
			{
				if((i/n+1)%2==1)
				{
					cout << i/n << " " << 1;
				}
				else
				{
					cout << i/n << " " << n;
				} 
			}
		}
		else
		{
			continue;
		}
	}
	return 0;
}
