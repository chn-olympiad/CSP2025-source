#include<bits/stdc++.h>
using namespace std;
int a[10001][3];
int n,m,ans=-1,res,h;
void f(int t,int r,int x,int y,int z)
{
	if(t==n+1)
	{
		ans=max(ans,r);
	}
	else
	{
		if (x<h)
		{
			r=r+a[t+1][0];
			f(t+1,r,x+1,y,z);
			r=r-a[t+1][0];
		}
		if (y<h)
		{
			r=r+a[t+1][1];
			f(t+1,r,x,y+1,z);
			r=r-a[t+1][1];
		}
		if (z<h)
		{
			r=r+a[t+1][2];
			f(t+1,r,x,y,z+1);
			r=r-a[t+1][2];
		}
	}

}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>m;
	while (m!=0)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		h=n/2;
		ans=-1;
		f(0,0,0,0,0);
		cout<<ans<<endl;
		m--;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}