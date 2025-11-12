#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T,n,m,b[N],b1[N],b2[N],b3[N];
struct node{
	int x,y,z;
}a[N];
bool cmp(node as,node bs)
{
	return as.x>bs.x;
}
bool cmp2(int as,int bs)
{
	return as>bs;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int half=n/2,ans=0,cnt=0,cnt2=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z==0) cnt2++;
			if(a[i].y==0&&a[i].z==0) cnt++;
		}
		if(cnt==n)
		{
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=half;i++) ans+=a[i].x;
		}
		else if(cnt2==n)
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i].y-a[i].x;
				ans+=a[i].x;
			}
			sort(b+1,b+n+1,cmp2);
			for(int i=1;i<=half;i++) ans+=b[i];
		}
		else
		{
			int f[4]={0};
			for(int i=1;i<=n;i++)
			{
				if(a[i].x>a[i].y&&a[i].x>a[i].z)
				{
					f[1]++;
					b1[f[1]]=max(a[i].y,a[i].z)-a[i].x;
					ans+=a[i].x;
				}
				else if(a[i].y>a[i].x&&a[i].y>a[i].z)
				{
					f[2]++;
					b2[f[2]]=max(a[i].x,a[i].z)-a[i].y;
					ans+=a[i].y;
				}
				else
				{
					f[3]++;
					b3[f[3]]=max(a[i].x,a[i].y)-a[i].z;
					ans+=a[i].z;
				}
			}
			int tot=0;
			if(f[1]>half)
			{
				sort(b1+1,b1+f[1]+1,cmp2);
				while(f[1]>half)
				{
					ans+=b1[++tot];
					f[1]--;
				}
			}
			else if(f[2]>half)
			{
				sort(b2+1,b2+f[2]+1,cmp2);
				while(f[2]>half)
				{
					ans+=b2[++tot];
					f[2]--;
				}
			}
			else
			{
				sort(b3+1,b3+f[3]+1,cmp2);
				while(f[3]>half)
				{
					ans+=b3[++tot];
					f[3]--;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
