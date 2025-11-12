#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int a,b,c,mu;
}x[100005];
bool cmp(Node a,Node b)
{
	return a.mu>b.mu;
}
Node t[4][100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int maxn=(n>>1);
		int i;
		long long ans=0;
		int cnt[4]={0,0,0,0};
		for(i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].a>=x[i].b&&x[i].a>=x[i].c)
			{
				ans+=x[i].a;
				x[i].mu=x[i].a-max(x[i].b,x[i].c);
				t[1][++cnt[1]]=x[i];
			}
			else if(x[i].b>=x[i].a&&x[i].b>=x[i].c)
			{
				ans+=x[i].b;
				x[i].mu=x[i].b-max(x[i].a,x[i].c);
				t[2][++cnt[2]]=x[i];
			}
			else
			{
				ans+=x[i].c;
				x[i].mu=x[i].c-max(x[i].a,x[i].b);
				t[3][++cnt[3]]=x[i];
			}
		}
		for(i=1;i<=3;i++)
		{
			if(cnt[i]>maxn)
			{
				sort(t[i]+1,t[i]+cnt[i]+1,cmp);
				int x=0;
				while(cnt[i]>maxn)
					ans-=t[i][cnt[i]--].mu;
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//Happy,meow.I think this is right. 