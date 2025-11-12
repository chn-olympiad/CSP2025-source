#include<bits/stdc++.h>
using namespace std;
bool cmp(int m,int n)
{
	return m>n;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	int b[100005],c=0,e;
	cin>>x>>y;
	cin>>c;
	b[1]=c;
	for(int i=2;i<=x*y;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+x*y+1,cmp);
	for(int i=1;i<=x*y;i++)
	{
		if(b[i]==c)
		{
			e=i;
			break;
		}
	}
	//cout<<e;
	int p,q;
	if(e%x==0)
	{
		p=e/x;
	}
	else
	{
		p=e/x+1;
	}
	if(p%2==0)
	{
		q=x-e%x;
		if(q==0)
		{
			q=1;
		}
	}
	else
	{
		q=e%x;
		if(q==0)
		{
			q=x;
		}
	}
	cout<<p<<" "<<q;
	return 0;
}
