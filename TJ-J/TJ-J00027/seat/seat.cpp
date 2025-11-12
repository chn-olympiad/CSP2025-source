#include<bits/stdc++.h>
using namespace std;
int n,m,R,z,cur=0,w,temp,l,h;
int a[105],s[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	cin>>R;
	a[1]=R;
	for(int i=2;i<=z;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+z+1,cmp);
	for(int i=1;i<=z;i++)
	{
		if(a[i]==R)
		{
			temp=i;
			break;
		}
	}
	if(temp%n==0)
	{
		l=temp/n;
	}
	else
	{
		l=temp/n+1;
	}
	h=temp%n;
	if(h==0)
	{
		h=n;
	}
	if(l%2==1)
	{
		cout<<l<<" "<<h;
	}
	else
	{
		cout<<l<<" "<<m-h+1;
	}
	return 0;
}
