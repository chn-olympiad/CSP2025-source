#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,num,pos,c,r,a[N];
bool cmp(int u,int v)
{
	return u>v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if (a[i]==num)
		{
			pos=i;
			break;
		}
	c=pos/(2*n)*2;
	pos%=2*n;
	if (pos>n)
	{
		c+=2;
		r=2*n+1-pos;
	}
	else
	{
		c++;
		r=pos;
	}
	cout<<c<<" "<<r<<"\n";
}
