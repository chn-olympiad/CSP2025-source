#include <bits/stdc++.h>
using namespace std;
int n,x[100010][5],t,maxx=-1;
void f(int step,int ans,int a,int b,int c)
{
	if(step>n)
	{
		maxx=max(ans,maxx);
		return;
	}
	if(a<n/2)
	{
		f(step+1,ans+x[step][1],a+1,b,c);
	}
	if(b<n/2)
	{
		f(step+1,ans+x[step][2],a,b+1,c);
	}
	if(c<n/2)
	{
		f(step+1,ans+x[step][3],a,b,c+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>x[i][j];
			}
		}
		f(1,0,0,0,0);
		cout<<maxx<<endl;
		maxx=-1;
	}
	
	return 0;
} 