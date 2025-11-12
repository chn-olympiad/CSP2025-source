#include<bits/stdc++.h>
using namespace std;
int const N=2e5+10;
int n;
int ans,sum;
int c[5],a[N][5];
int x[N],y[N],z[N];
bool Cmp(int x,int y){return x<y;}
void solve()
{
	int q=0,w=0,e=0;
	for(int i=1;i<=n;i++)
	{
		int goal=max(a[i][1],max(a[i][2],a[i][3]));
		if(goal==a[i][1])
		{
			q++;
			x[q]=abs(a[i][1]-max(a[i][2],a[i][3]));
		}else 
		if(goal==a[i][2])
		{
			w++;
			y[w]=abs(a[i][2]-max(a[i][1],a[i][3]));
		}else
		{
			e++;
			z[e]=abs(a[i][3]-max(a[i][1],a[i][2]));
		}
	}
	int m=n/2;
	if(c[1]>m) 
	{
		sort(x+1,x+q+1,Cmp);
		c[1]-=m;
		for(int i=1;i<=c[1];i++)
			sum-=x[i];
	}else
	if(c[2]>m)
	{
		sort(y+1,y+w+1,Cmp);
		c[2]-=m;
		for(int i=1;i<=c[2];i++)
			sum-=y[i];
	}else
	if(c[3]>m)
	{
		sort(z+1,z+e+1,Cmp);
		c[3]-=m;
		for(int i=1;i<=c[3];i++)
			sum-=z[i];
	}
	printf("%d\n",sum);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		c[1]=0;c[2]=0;c[3]=0;
		for(int i=1;i<=n;i++)
		{
			int p=0,num=0;
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]>num) 
				{
					num=a[i][j];
					p=j;
				}
			}
			sum+=num;	
			c[p]++;
		}
		solve();
	}
	return 0;
 } 
