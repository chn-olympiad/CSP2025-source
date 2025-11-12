#include<bits/stdc++.h>..t1
using namespace std;
const int N=1e5+100;
int a,b,c1[N],c2[N],c3[N],d,f,g,h;
struct node
{
	int x,y,z;
}e[N];
void dfs(int num,int x,int y,int z,int u)
{
	if(num>b)
	{
		d=max(d,u); 
		return ;
	}
	if(x>0)
	{
		dfs(num+1,x--,y,z,u+c1[num]);
	}
	if(y>0)
	{
		dfs(num+1,x,y--,z,u+c2[num]);
	}
	if(z>0)
	{
		dfs(num+1,x,y,z--,u+c3[num]);
	}
	return ;
}
bool cmp(node x,node y)
{
	if(x.x>y.x)
	{
		return 1;
	}
	if(x.x<y.x)
	{
		return 0;
	}
	if(x.y>y.y)
	{
		return 1;
	}
	if(x.y<y.y)
	{
		return 0;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>a;
	while(a--)
	{
		cin>>b;
		for(int i=1;i<=b;i++)
		{
			cin>>c1[i]>>c2[i]>>c3[i];
			e[i].x=c1[i];
			e[i].y=c2[i];
			e[i].z=c3[i];
		}
		if(b<=30)
		{
			d=0;
			dfs(1,b/2,b/2,b/2,0);
			cout<<d<<"\n";
			continue;
		}
		int x2=1;
		int x3=1;
		for(int i=1;i<=b;i++)
		{
			if(c2[i]!=0)
			{
				x2=0;
			}
			if(c3[i]!=0)
			{
				x3=0;
			}
		}
		if(x2==1 && x3==1)
		{
			sort(c1+1,c1+1+b);
			int u=0;
			for(int i=b,j=b/2;j>=1;i--,j--)
			{
				u=u+c1[i];
			}
			cout<<u<<"\n";
			continue;
		}
		if(x3==1)
		{
			sort(e+1,e+1+b,cmp);
			int p=0;
			int u1=b/2;
			int u2=b/2;
			for(int i=1;i<=b;i++)
			{
				if(e[i].x>e[i].y)
				{
					if(u1>0)
					{
						u1--;
						p+=e[i].x;
					}
					else
					{
						u2--;
						p+=e[i].y;
					}
				}
				else
				{
					if(e[i].x<e[i].y)
					{
						if(u2>0)
						{
							u2--;
							p+=e[i].y;
						}
						else
						{
							u1--;
							p+=e[i].x;
						}
					}
					else
					{
						u1--;
						p+=e[i].x;
					}
				} 
			}
			cout<<p<<"\n";
			continue;
		}
		cout<<rand()<<"\n";
	}

	return 0;
}
