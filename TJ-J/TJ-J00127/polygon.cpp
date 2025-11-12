#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int gun[n];
	for(int i=0;i<n;i++)
	{
		cin>>gun[i];
	}
	int cnt=0;
	sort(gun,gun+n,cmp);
	for(int i=3;i<=n;i++)
	{
		if(gun[0]+gun[1]+gun[2]>2*gun[0]) cnt++;
	}
	cout<<cnt;
	return 0;
}
