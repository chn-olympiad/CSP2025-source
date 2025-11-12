#include<bits/stdc++.h>
using namespace std;
long long a[101];
long long p;
long long c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	if(c==0)c=1;
	for(int i=1;i<=c*r;i++)
	{
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+c*r+1);
	for(int i=1;i<=c*r;i++)
	{
		if(a[i]==p)
		{
			p=i;
			break;
		}
	}
	p=c*r-p;
	int x,y;
	if((p/c)%2==0)
	{
		x=(p/c+1);
		y=(p%c+1);
	}
	else
	{
		x=(p/c+1);
		y=r-(p%c);
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
