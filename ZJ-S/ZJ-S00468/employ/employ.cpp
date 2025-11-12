#include<bits/stdc++.h>
using namespace std;
const int N=510;
int n,m;
string a;
int c[N];
int b[N];
int ans;
void dfs(int x,int y,int z)
{
//	cout<<ans<<endl;
	if(x==n)
	{
		if(z>=m)
		ans=(ans+1)%998244353;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(c[i]==0)
		{
			c[i]=1;
			if(y>=b[i])
			{
				dfs(x+1,y+1,z);
			}
			else
			{
				if(a[x]=='1')
				{
					//cout<<1;
					dfs(x+1,y,z+1);
				}
				
				else
				dfs(x+1,y+1,z);
			}
			c[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
cin>>n>>m;
cin>>a;
for(int i=0;i<n;i++)
{
	cin>>b[i];
}
dfs(0,0,0);
cout<<ans;
	return 0;
}
/*5 4 4
1 2 1000
2 3 1000
3 4 1000
4 5 1000
3 0 0 0 0 0
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1*/
