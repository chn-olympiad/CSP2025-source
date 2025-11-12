#include<bits/stdc++.h>
using namespace std;
int n,cnt;
struct node
{
	int x,y;
}a[5500];
bool cmp(node aa,node bb)
{
	return aa.x<bb.x;
}

main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>n;
	if(n<=2)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+1+n,cmp);
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		if(i!=j&&i!=k&&j!=k)
		if(a[a[i].y].x+a[a[j].y].x+a[a[k].y].x>a[n].x*2) cnt++;
	}
	if(n==4)
	{
		for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		for(int k=1;k<=4;k++)
		for(int l=1;l<=4;l++)
		if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
		if(a[a[i].y].x+a[a[j].y].x+a[a[k].y].x+a[a[l].y].x>a[n].x*2) cnt++;
	}
	cout<<cnt;
}












