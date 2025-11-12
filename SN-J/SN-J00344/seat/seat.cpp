#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long p=1,q=1,l;
long long x[20],y[20],b[110];
bool c=true;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++)
	{
		cin>>b[i];
	}
	ans=b[1];
	sort(b+1,b+l+1);
	for(int i=l;i>=1;i--)
	{
		if(i==l)
		{
			x[b[i]]=p;
			y[b[i]]=q;
			continue;
		}
		if(c==true)
		{
			p++;
			if(p>n)
			{
				p--;
				q++;
				c=!c;
				x[b[i]]=p;
				y[b[i]]=q;
				continue;
			}
			x[b[i]]=p;
			y[b[i]]=q;
			continue;
		}
		else
		{
			p--;
			if(p<1)
			{
				p++;
				q++;
				c=!c;
				x[b[i]]=p;
				y[b[i]]=q;
				continue;
			}
			x[b[i]]=p;
			y[b[i]]=q;
		}
	}
	cout<<y[ans]<<" "<<x[ans];
	return 0;
}
