#include<bits/stdc++.h>
using namespace std;
int m,n,pos,hs,ls;
int a[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			pos=i;
			break;
		}
	}
	int ys=pos%n;
	int ss=pos/n;
	if(ys==0)
	{
		ls=ss;
		hs=n;
	}
	else
	{
		ls=ss+1;
		if(ls%2==0)
		{
			hs=n-ys+1;
		}
		else
		{
			hs=ys;
		}
	}
	cout<<ls<<" "<<hs;
	return 0;
}
