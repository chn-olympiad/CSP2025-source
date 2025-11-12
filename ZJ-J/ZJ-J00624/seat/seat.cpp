#include<bits/stdc++.h>
using namespace std;
long long a[15*15];
long long s[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	  cin>>a[i];
	long long k=a[1];
	sort(a+1,a+1+n*m,greater<long long>());
	long long x=1,y=1,f=1;
	for(long long i=1;i<=n*m;i++)
	{
		if(a[i]==k) 
		{
			cout<<y<<" "<<x;
			return 0;
		}
		if(f==1) 
		{
			if(x<n) x++;
			else 
			{
				f*=-1;
				y++;
			}
		}
		else 
		{
			if(x>1) x--;
			else 
			{
				f*=-1;
				y++;
			}
		}
	}
	return 0;
}
