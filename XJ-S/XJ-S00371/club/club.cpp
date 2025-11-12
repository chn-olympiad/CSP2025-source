#include<bits/stdc++.h>
using namespace std;
int ji[5];
struct node
{
	int x,y,z;
	int ld,md,sd;
}a[100005];
int solve1(int ji[],int n,int maxans)
{
	while(ji[1]>n/2)
	{
		int minld,xb;
		for(int i=1;i<=n;i++)
		{
			minld=min(minld,a[i].ld);
			if(minld==a[i].ld)
				xb=i;
		}
		ji[1]--;
		maxans+=a[xb].md;
	}
	return maxans;
}

int solve2(int ji[],int n,int maxans)
{
	while(ji[2]>n/2)
	{
		int minld,xb;
		for(int i=1;i<=n;i++)
		{
			minld=min(minld,a[i].ld);
			if(minld==a[i].ld)
				xb=i;
		}
		ji[2]--;
		maxans+=a[xb].md;
	}
	return maxans;
}

int solve3(int ji[],int n,int maxans)
{
	while(ji[3]>n/2)
	{
		int minld,xb;
		for(int i=1;i<=n;i++)
		{
			minld=min(minld,a[i].ld);
			if(minld==a[i].ld)
				xb=i;
		}
		ji[3]--;
		maxans+=a[xb].md;
	}
	return maxans;
}

int solve(int ji[],int n,int maxans)
{
	while(ji[1]>n/2||ji[2]>n/2||ji[3]>n/2)
	{
		if(ji[1]>n/2)
			solve1(ji,n,maxans);	
		if(ji[2]>n/2)
			solve2(ji,n,maxans);	
		if(ji[3]>n/2)
			solve3(ji,n,maxans);	
	}
	return  maxans;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,maxans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			int maxn=max(max(a[i].x,a[i].y),a[i].z);
			int minn=min(min(a[i].x,a[i].y),a[i].z);
			a[i].ld=maxn;
			a[i].md=a[i].x+a[i].y+a[i].z-maxn-minn;
			a[i].sd=minn;
			if(maxn==a[i].x)
				ji[1]++;
			else if(maxn==a[i].y)
				ji[2]++;
			else if(maxn==a[i].z)
				ji[3]++;
		}
		
		if(ji[1]<=n/2&&ji[2]<=n/2&&ji[3]<=n/2)
			cout<<ji[1]+ji[2]+ji[3];
		else
		{
			if(ji[1]>n/2)
			{
				cout<<solve1(ji,n,maxans);	
			}
			else if(ji[2]>n/2)
			{
				cout<<solve2(ji,n,maxans);	
			}
			else if(ji[3]>n/2)
			{
				cout<<solve3(ji,n,maxans);	
			}
		}
	}
	return 0;
} 
