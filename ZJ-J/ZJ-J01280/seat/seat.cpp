#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,b,c,d,t,a[101];
bool cmp(int q,int h)
{
	return q>h;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)	cin>>a[i];
	b=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++)
	{
		if(a[i]==b)
		{
			c=i;
			break;
		}
	}
	t=c/(n*2)*2;
	d=c%(n*2);
	if(d==0)
	{
		d++;
	}
	else if(d>n)
	{
		t+=2;
		d=n*2-d+1;
	}
	else
	{
		t++;	
	}
	cout<<t<<" "<<d;
	return 0;
}
