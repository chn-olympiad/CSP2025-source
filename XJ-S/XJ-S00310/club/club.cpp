#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int x,y,z;
}q[100005];
int main()
{
	long long int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		long long int p[5]={0};
		long long int mayn=0,mazn=0,k=0,ans=0,i=0,j=0,n=0,m=0,a[100005]={0},b[100005]={0},manyidu=0,maxn=0;
		cin>>n;
		for(i=1;i<=n;i++)
		cin>>q[i].x>>q[i].y>>q[i].z;
		if(q[1].y==q[1].z==0&&q[2].y==q[2].z==0&&q[10].y==q[10].z==0&&q[10000].y==q[10000].z==0&&q[100000].y==q[100000].z==0&&q[6].y==q[6].z==0)
		{
			for(i=1;i<=n;i++)
			{
			ans+=q[i].x; 
		}
		cout<<ans<<endl;
	}
	for(i=1;i<=n;i++)
	{
	
		if(q[i].x>=q[i].y&&q[i].x>=q[i].z&&maxn<=(n/2))
		{
			manyidu+=q[i].x;
			maxn++;
		}
		if(maxn>(n/2))
		{
			manyidu=manyidu-q[i-1].x+q[i-1].y;
			maxn--;
		}
		if(mayn>(n/2))
		{
			manyidu=manyidu-q[i-1].y+q[i-1].z;
			mayn--;
		}
		if(q[i].y>=q[i].z&&q[i].y>=q[i].x&&mayn<=(n/2))
		{
			manyidu+=q[i].y;
			mayn++;
		}
				if(mazn>(n/2))
		{
			manyidu=manyidu-q[i-1].z+q[i-1].x;
			mazn--;
		}
		if(q[i].z>=q[i].y&&q[i].z>=q[i].x&&mazn<=(n/2))
		{
			manyidu+=q[i].z;
			mazn++;
		}
	}
	cout<<manyidu<<endl;
}
	return 0;
 }
