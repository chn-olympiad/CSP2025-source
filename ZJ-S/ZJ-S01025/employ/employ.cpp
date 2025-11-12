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
int nn,mm;
string str;
int cc[100010];
long long num = 0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>nn>>mm>>str;
	for(int i = 1;i<=n;i++)
	{
		cin>>cc[i];
		num+=cc[i];
		num%=998224353;
	}
	cout<<num;
	
	return 0;
}
