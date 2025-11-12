#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long sco;
	long long x,y;
} a[1000010];
int cmp(node nx,node ny)
{
	return nx.sco>ny.sco;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,nm,x=1,y=1,a1=0;
	scanf("%lld %lld", &n, &m);
	nm=n*m;
	for(int i=1; i<=nm; i++)
	{
		cin>>a[i].sco;
	}
	a1=a[1].sco;
	sort(a+1,a+nm+1,cmp);
	for(int i=1; i<=nm; i++)
	{
		if(a[i].sco==a1)
		{
			a1=i;
			break;
		}
	}
	for(int i=1; i<=nm; i++)
	{
		a[i].x=x;
		a[i].y=y;
		if(x==n&&y%2)
		{
			y++;
			continue;
		}
		else if(x==1&&y%2==0)
		{
			y++;
			continue;
		}
		else if(y%2==0&&x>1)
		{
			x--;
			continue;
		}
		else if(y%2==1&&x<n)
		{
			x++;
			continue;
		}
	}
	cout<<a[a1].y<<" "<<a[a1].x;
	return 0;
}
