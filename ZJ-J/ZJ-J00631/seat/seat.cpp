#include<bits/stdc++.h>
using namespace std;

long long a[105];
bool cmp(long long a,long long b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,sea,h=1,l=1;
	bool x=true;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sea=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++)
	{
		if(a[i]==sea)
		{
			cout<<l<<' '<<h;
			break;
		}
		if(h==n&&x)
		{
			x=false;
			++l;
		}
		else if(h==1&&(!x))
		{
			x=true;
			++l;
		}
		else
		{
			if(x)
				++h;
			else
				--h;
		}
	}
	return 0;
}