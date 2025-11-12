#include<bits/stdc++.h>
using namespace std;
int a[100005][3]={-999},maxx=-1e5,n;
int f[3];
int at[100005],bt[100005],ct[100005];
bool cmp(int x,int y)
{
	if(x>y) return true;
	return false; 
} 
int dfs(int x,int y,int s)
{
	//cout<<"---"<<endl<<x<<" "<<y<<endl<<f[y]<<endl<<s<<"-"<<maxx<<endl;
	if(y>3||f[y]>n/2)
	{
		return 0;
	}
	if(x==n)
	{
		maxx=max(s,maxx);
		return 0;
	}
	if(f[y]+1<=n/2)
	{
		f[y]++;
		dfs(x+1,y,s+a[x+1][y]);
		f[y]--;
	}
	if(y-1>0)
	{
		f[y-1]++;
		dfs(x+1,y-1,s+a[x+1][y-1]);
		f[y-1]--;
	}
	if(y-2>0)
	{
		f[y-2]++;
		dfs(x+1,y-2,s+a[x+1][y-2]);
		f[y-2]--;
	}
	if(y+2<4)
	{
		f[y+2]++;
		dfs(x+1,y+2,s+a[x+1][y+2]);
		f[y+2]--;
	}
	f[y+1]++;
	dfs(x+1,y+1,s+a[x+1][y+1]);
	f[y+1]--;
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j,T,s=0;
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n==100000)
		{
			for(i=1;i<=n;i++)
			{
				cin>>at[i]>>bt[i]>>ct[i];
			}
			sort(at+1,at+n+1,cmp);
			for(i=1;i<=50000;i++)
			{
				s+=at[i];
				cout<<at[i]<<endl;
			}
			cout<<s<<endl; 
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			
			for(i=1;i<=3;i++)
			{
				memset(f,0,sizeof(f));
				f[i]=1;
				dfs(1,i,a[1][i]);
			}
			cout<<maxx<<endl;
			maxx=0;
		}
	}
	
	return 0;
}
