#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct node
{
	int x;int y;int z;
}a[100010];
bool cmdA(node a,node b)
{
	return a.x>b.x;
}
int numA,numN;
bool xz,yz,zz;
int numB;
int vis[100010];
void dfsN(int now,int vis[],int numx,int numy,int numz)
{
	if(numx>n/2)
	{
		return;
	}
	if(numy>n/2)
	{
		return;
	}
	if(numz>n/2)
	{
		return;
	}
	if(now == n+1)
	{
		int sun = 0;
		
		for(int i = 1;i<=n;i++)
		{
			if(vis[i] == 1)
			{
				sun+=a[i].x;
			}
			if(vis[i] == 2)
			{
				sun+=a[i].y;
			}
			if(vis[i] == 3)
			{
				sun+=a[i].z;
			}
		}
		numN = max(numN,sun);
		return;
	}
	vis[now] = 1;
	numx++;
	dfsN(now+1,vis,numx,numy,numz);
	numx--;
	vis[now] = 2;
	numy++;
	dfsN(now+1,vis,numx,numy,numz);
	numy--;
	vis[now] = 3;
	numz++;
	dfsN(now+1,vis,numx,numy,numz);
	numz--;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	numA = 0;
	while(T--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		xz = 1;
		yz = 1;
		zz = 1;
		for(int i = 1;i<=n;i++)
		{
			if(a[i].x != 0)
			{
				xz = 0;
				break;
			}
			if(a[i].y != 0)
			{
				yz = 0;
				break;
			}
			if(a[i].z != 0)
			{
				zz = 0;
				break;
			}
		}
		if(n == 100000&&yz&&zz)
		{
			numA = 0;
			sort(a+1,a+n+1,cmdA);
			for(int i = 1;i<=n/2;i++)
			{
				numA +=a[i].x;
			}
			cout<<numA<<endl;
			continue;
		}
		if((n == 200||n == 100000)&&zz)
		{
			numB = 0;
			
		}
		if(n<=30)
		{
			numN = 0;
			memset(vis,0,sizeof(vis));
			int numx,numy,numz;
			numx = 0;
			numy = 0;
			numz = 0;
			dfsN(1,vis,numx,numy,numz);
			cout<<numN<<endl;
		}
	}
	return 0;
}
