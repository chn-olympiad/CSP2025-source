#include<bits/stdc++.h>
using namespace std;
int f[30][30][30][30];
int a[100010][10],b[100010];
int solve(int p,int x,int y,int z)
{
	if(f[p][x][y][z]!=0)return f[p][x][y][z];
	if(p==0)return 0;
//	cout<<x<<" "<<y<<" "<<z<<"\n";
	if(x==0&&y==0)return f[p][x][y][z]=solve(p-1,x,y,z-1)+a[p][3];
	if(x==0&&z==0)return f[p][x][y][z]=solve(p-1,x,y-1,z)+a[p][2];
	if(y==0&&z==0)return f[p][x][y][z]=solve(p-1,x-1,y,z)+a[p][1];
	if(x==0)return f[p][x][y][z]=max(solve(p-1,x,y-1,z)+a[p][2],solve(p-1,x,y,z-1)+a[p][3]);
	if(y==0)return f[p][x][y][z]=max(solve(p-1,x-1,y,z)+a[p][1],solve(p-1,x,y,z-1)+a[p][3]); 
	if(z==0)return f[p][x][y][z]=max(solve(p-1,x-1,y,z)+a[p][1],solve(p-1,x,y-1,z)+a[p][2]); 
	return f[p][x][y][z]=max(max(solve(p-1,x-1,y,z)+a[p][1],solve(p-1,x,y-1,z)+a[p][2]),solve(p-1,x,y,z-1)+a[p][3]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(f,0,sizeof(f));
		int n;
		cin>>n;
		bool yes=0;
		for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		//pppppppppp
		for(int i=1;i<=n;i++)
			if(a[i][2]!=0||a[i][3]!=0)
			{
				yes=1;
				continue;
			}
		if(yes==0)
		{
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1);
			int ans=0;
			for(int i=n;i>n/2;i--)ans+=b[i];
			cout<<ans<<"\n";
		}
		//ppppppppppp
		else
		{
			int maxx=0;
			for(int x=0;x<=n/2;x++)
			{
				for(int y=0;y<=n/2;y++)
				{
					int z=n-x-y;
					if(z>n/2)continue;
					maxx=max(maxx,solve(n,x,y,z));
				}
			}
			cout<<maxx<<"\n";
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
