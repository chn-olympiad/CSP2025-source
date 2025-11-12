#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans=0,s=0;
struct node{
	ll id,x;
};
node a[10][100010];
ll vis[5],vis2[100010],na[100010];
bool cmp(node A,node B)
{
	return A.x<B.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club1.in","r",stdin);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0,s=0;
		cin>>n;
//		cout<<n<<endl;
		memset(vis,0,sizeof vis);
		memset(vis2,0,sizeof vis2);
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i].x>>a[2][i].x>>a[3][i].x;
			if(a[1][i].x>a[2][i].x&&a[1][i].x>a[3][i].x)
			{
				vis[1]++;
				s+=a[1][i].x;
				na[i]=1;
			}
			else if(a[2][i].x>a[3][i].x)
			{
				vis[2]++;
				s+=a[2][i].x;
				na[i]=2;
			}
			else
			{
				vis[3]++;
				s+=a[3][i].x;
				na[i]=3;
			}
			a[1][i].id=a[2][i].id=a[3][i].id=i;
		}
		int x=0;
		if(vis[1]>n/2)
		{
			x=1;
		}
		else if(vis[2]>n/2)
		{
			x=2;
		}
		else if(vis[3]>n/2)
		{
			x=3;
		}
		else
		{
			cout<<s<<"\n";
			continue;
		}
		for(int i=1;i<=3;i++)
		{
			if(i==x)
			{
				continue;
			}
			for(int j=1;j<=n;j++)
			{
				if(na[j]==x)
				{
					a[i][j].x=a[x][j].x-a[i][j].x;
				}
				else
				{
					a[i][j].x=INT_MAX;
				}
//				cout<<a[i][j].x<<endl;
			}
			sort(a[i]+1,a[i]+1+n,cmp);
		}
//		cout<<a[3][1].x<<" "<<a[3][1].id;
		int cnt[5]={1,1,1,1};
		while(vis[x]>n/2)
		{
			int y=1e5,z;
			for(int i=1;i<=3;i++)
			{
//				cout<<endl;
				if(i==x)
				{
					continue;
				}
				if(vis[i]+1>n/2)
				{
					continue;
				}
				if(y>a[i][cnt[i]].x)
				{
					y=a[i][cnt[i]].x;
//					cout<<y<<" "<<z;
					z=i;
				}
			}
			if(!vis2[a[z][cnt[z]].id])
			{
//				cout<<z<<" "<<cnt[z];
//				cout<<a[z][cnt[z]].id<<endl;
				vis[x]--;
				vis[z]++;
				vis2[a[z][cnt[z]].id]=1;
//				cout<<y<<endl;
				s-=y;
			}
			cnt[z]++;
		}
		cout<<s<<"\n";
	}
	return 0;
}
