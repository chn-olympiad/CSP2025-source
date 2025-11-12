#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,ans;
bool f;
struct Club{
	int x,y,z;
}a[N];
void Dfs(int i,int cnt,int A,int b,int c)
{
	if(i>n)
	{
		ans=max(ans,cnt);
		return ;
	}
	if(A<n/2)
		Dfs(i+1,cnt+a[i].x,A+1,b,c);
	if(b<n/2)
		Dfs(i+1,cnt+a[i].y,A,b+1,c);
	if(c<n/2)
		Dfs(i+1,cnt+a[i].z,A,b,c+1);
}
bool Cmp(Club a,Club b)
{
	if(a.x==b.x)
	{
		if(a.y==b.y)
			return a.z>b.z;
		return a.y>b.y;
	}
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		f=1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y||a[i].z)f=0;
		}
		sort(a+1,a+n+1,Cmp);
		if(n<=30)
			Dfs(1,0,0,0,0);
		else if(f)
		{
			for(int i=1;i<=n;i++)
				ans+=a[i].x;
		}
		else
		{
			int cnt[4]={},m=n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].z>a[i].y && a[i].z>a[i].x)
				{
					if(cnt[3]<m)
					{
						ans+=a[i].z;
						cnt[3]++;
					}
					else
					{
						if(a[i].x>a[i].y && cnt[1]<m)
						{
							cnt[1]++;
							ans+=a[i].x;
						}
						else
						{
							cnt[2]++;
							ans+=a[i].y;
						}
					}
				}
				else if(a[i].y>a[i].z && a[i].y>a[i].x)
				{
					if(cnt[2]<m)
					{
						ans+=a[i].y;
						cnt[2]++;
					}
					else
					{
						if(a[i].x>a[i].z && cnt[1]<m)
						{
							cnt[1]++;
							ans+=a[i].x;
						}
						else
						{
							cnt[3]++;
							ans+=a[i].z;
						}
					}
				}
				else
				{
					if(cnt[1]<m)
					{
						ans+=a[i].x;
						cnt[1]++;
					}
					else
					{
						if(a[i].z>a[i].y && cnt[3]<m)
						{
							cnt[3]++;
							ans+=a[i].z;
						}
						else
						{
							cnt[2]++;
							ans+=a[i].y;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

