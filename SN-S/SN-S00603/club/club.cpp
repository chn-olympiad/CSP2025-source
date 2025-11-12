#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
bool fa,fb;


struct S
{
	int a,b,c;
	char d1,d2;
}s[100010];
bool cmpa(S x,S y)
{
	return x.a>y.a;
}
bool cmpb(S x,S y)
{
	return x.a-x.b>y.a-y.b;
}

void dfs(int p, int m,int x,int y,int z)
{
	if(x+y+z==n)
	{
		ans=max(ans,m);
		return;
	}
	if(x<n/2)
	{
		dfs(p+1,m+s[p+1].a,x+1,y,z);
	}
	if(y<n/2)
	{
		dfs(p+1,m+s[p+1].b,x,y+1,z);
	}
	if(z<n/2)
	{
		dfs(p+1,m+s[p+1].c,x,y,z+1);
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--)
	{
		fa=0;fb=0;ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0)
			{
				fa=1;
			}
			if(s[i].c!=0)
			{
				fb=1;
			}	
		}
		
		
		
		if(!fa)
		{
			sort(s+1,s+n+1,cmpa);
			for(int i=1;i<=n/2;i++)
			{
				ans+=s[i].a;
			}
			cout<<ans<<"\n";
		}
		
		else if(!fb)
		{
			sort(s+1,s+n+1,cmpb);
			for(int i=1;i<=n/2;i++)
			{
				ans+=s[i].a;
				ans+=s[n-i+1].b;
			}
			cout<<ans<<"\n";
		}
		
		else
		{
			dfs(1,s[1].a,1,0,0);
			dfs(1,s[1].b,0,1,0);
			dfs(1,s[1].c,0,0,1);
			cout<<ans<<"\n";
		}
		
		
	}

	
	return 0;
}






