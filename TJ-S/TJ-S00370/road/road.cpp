#include<bits/stdc++.h>
using namespace std;

long long n,m,k;
struct node1
{
	long long n,v,w;
}a[100060];
struct node2
{
	long long c,num[100060];
}b[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long cnt=0,fl=0;
	for(long long i=1;i<=m;i++)
	{
		cin>>a[i].n>>a[i].v>>a[i].w;
		cnt+=a[i].w; 
	}
	if(n==m && k==0)
	{
		cout<<cnt;
		fclose(stdin);
		fclose(stdout);
		return 0;
	 } 
	for(long long i=1;i<=k;i++)
	{
		cin>>b[i].c;
		if(b[i].c!=0)
		{
			fl=1;
		}
		for(long long j=1;j<=m;j++)
		{
			cin>>b[i].num[j];
		}
	}
	if(fl==0)
	{
		cnt=0;
		for(long long i=1;i<=m;i++)
		{
			long long minn=2000000000;
			for(long long j=1;j<=k;j++)
			{
				minn=min(minn,b[j].num[i]);
			}
			cnt+=minn;
		}
		cout<<cnt;
		fclose(stdin);
		fclose(stdout); 
		return 0;
	}
	else
	{
		cout<<cnt;
		fclose(stdin);
		fclose(stdout); 
		return 0;
	}
 } 

