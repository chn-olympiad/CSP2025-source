#include<bits/stdc++.h>
using namespace std;
int a[10050];//道路指向 
int b[10050];//道路指向 
int c[10050];//道路价格 
struct note
{
	int n;
	int d[10050]; 
}contry[10050];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(a[i]>b[i])
		{
			swap(a[i],b[i]);
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>contry[i].n;
		for(int j=1;j<=m;j++)
		{
			cin>>contry[i].d[j];
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		ans+=c[i];
	}
	cout<<ans;
	return 0;
}
