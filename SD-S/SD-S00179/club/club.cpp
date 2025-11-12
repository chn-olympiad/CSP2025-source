#include<bits/stdc++.h>
using namespace std;
int T,n,ans;
bool s[100005][4];
struct node2
{
	int i,x;
};
node2 b[100005];
struct node
{
	int a,b,c;
};
node a[100005];
bool cmp(node2 a,node2 b)
{
	return a.x<b.x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(s,1,sizeof(s));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
		for(int i=1;i<=n;i++)
		{
			b[i].i=i;
			b[i].x=min(a[i].a-a[i].b,a[i].a-a[i].c);
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++)
			s[b[i].i][1]=0;
		for(int i=1;i<=n;i++)
		{
			b[i].i=i;
			b[i].x=a[i].b-a[i].c;
			if(s[i][1])
				b[i].x=min(a[i].b-a[i].a,b[i].x);
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++)
			s[b[i].i][2]=0;
		for(int i=1;i<=n;i++)
		{
			b[i].i=i;
			if((!s[i][1])&&(!s[i][2]))
				b[i].x=1e9;
			else if(s[i][1]&&s[i][2])
				b[i].x=min(a[i].c-a[i].a,a[i].c-a[i].b);
			if(s[i][1])
				b[i].x=a[i].c-a[i].a;
			if(s[i][2])
				b[i].x=a[i].c-a[i].b;
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n/2;i++)
			s[b[i].i][3]=0;
		ans=0;
		for(int i=1;i<=n;i++)
			ans+=max(s[i][1]*a[i].a,max(s[i][2]*a[i].b,s[i][3]*a[i].c));
		cout<<ans<<'\n';
	}
	return 0;
}
