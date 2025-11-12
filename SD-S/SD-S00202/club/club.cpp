#include<bits/stdc++.h>
using namespace std;

inline int read();
const int N=1e5+10; 

struct node{int x,s;};
struct nodde{int x,s,o;};

node a[4][N];
nodde xq[N];
bool bt[N];

inline bool cmp(node x,node y)
{
	if(x.x==y.x)return x.s>y.s;
	return x.x>y.x;
}

int sum;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(xq,0,sizeof(xq));
		memset(bt,0,sizeof(bt));
		sum=0;
		int n=read();
		
		for(int i=1;i<=n;i++)
		{
			a[1][i]={read(),i};
			a[2][i]={read(),i};
			a[3][i]={read(),i};
		}
		
		stable_sort(a[1]+1,a[1]+n+1,cmp);
		stable_sort(a[2]+1,a[2]+n+1,cmp);
		stable_sort(a[3]+1,a[3]+n+1,cmp);
		
		for(int i=1;i<=n>>1;i++)
		{
			xq[a[1][i].s]={a[1][i].x,1,a[1][i].s};
			bt[a[1][i].s]=1;
		}
		
		a[1][0].x=a[2][0].x=a[3][0].x=n>>1;
		
		for(int i=2;i<=3;i++)
		{
			for(int j=1;j<=a[i][0].x&&j<=n;j++)
			{
				int p=a[i][j].s;
				if(a[i][j].x==a[i][j+1].x)a[i][0].x++;
				if(bt[p])
				{
					int k=xq[p].o+1;
					while(k<=n&&bt[k]==1)k++;
					if(k==n+1)
					{
						if(xq[p].x>a[i][j].x)
						{
							continue;
						}
						else
						{
							xq[p]={a[i][j].x,i,p};
						}
					}
					else 
					{
						if(xq[p].x>a[i][j].x+a[xq[p].s][k].x)
						{
							continue;
						}
						else
						{
							bt[k]=1;
							bt[p]=1;
							xq[k]={a[xq[p].s][k].x,xq[p].s,k};
							xq[p]={a[i][j].x,i,p};
						}
					}
				}
				else
				{
					xq[p]={a[i][j].x,i,p};
					bt[p]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)sum+=xq[i].x;
		printf("%d\n",sum);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

inline int read()
{
	int x=0,s=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')s=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*s;
}

