#include<bits/stdc++.h>
using namespace std;
long long int n,k,a[500005],x=1,y=1,sum=1,ans,vis[1005][1005];
struct node
{
	int x[15005];
}b[15005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		b[i].x[i]=a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			b[i].x[j]=b[i].x[j-1]^a[j];	
	while(sum<=n)
	{
		if(b[x].x[y]==k&&vis[x][y]==0)
		{
			ans++;
			for(int i=1;i<=x;i++)
				for(int j=x;j<=n;j++)
					vis[i][j]=1;
		}
		x++;
		y++;
		if(y>n)
		{
			sum++;
			x=1;
			y=sum;
		}
	}
	cout<<ans;
	return 0;
}
