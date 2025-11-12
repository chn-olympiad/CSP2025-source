#include<bits/stdc++.h>
using namespace std;
int a[5050];
int x=3;
int n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(a[2]+a[3]>a[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
