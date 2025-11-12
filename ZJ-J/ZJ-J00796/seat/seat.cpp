#include<bits/stdc++.h>
using namespace std;
struct f
{
	int x,y;
} b[1000];
bool cmp(int b,int c)
{
	return b>c;
}
int n,m,a[1000],t;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[(i-1)*n+j];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,ax=1,ay=0;
	while(i<=n*m)
	{
		b[i].x=ax;
		if(ax%2==1) b[i].y=++ay;
		else b[i].y=ay--;
		if(ay==n||ay==0) ax++;
		i++;
	}
	for(int i=1;i<=m*n;i++)
		if(a[i]==t) 
		{
			cout<<b[i].x<<" "<<b[i].y;
			return 0;
		}
	return 0;
}
