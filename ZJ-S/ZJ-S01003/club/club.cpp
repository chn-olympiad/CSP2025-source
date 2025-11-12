#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,ka,kb,kc,fa[100100],fb[100100],fc[100100],f[20100],ans;
struct club
{
	int a;
	int b;
	int c;
}a[100100];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ka=0;kb=0;kc=0;ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a>=a[i].b&&a[i].a>=a[i].c) fa[++ka]=i,ans+=a[i].a;
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c) fb[++kb]=i,ans+=a[i].b;
			else if(a[i].c>=a[i].a&&a[i].c>=a[i].b) fc[++kc]=i,ans+=a[i].c;
		}
		if(ka>n/2)
		{
			memset(f,0,sizeof(f));
			for(int i=1;i<=ka;i++) f[a[fa[i]].a-max(a[fa[i]].b,a[fa[i]].c)]++;
			bool p=false;
			for(int i=0;i<=20000;i++)
			{
				for(int j=1;j<=f[i];j++)
				{
					ans-=i;
					ka--;
					if(ka<=n/2)
					{
						p=true;
						break;
					}
				}
				if(p) break;
			}
		}
		else if(kb>n/2)
		{
			memset(f,0,sizeof(f));
			for(int i=1;i<=kb;i++) f[a[fb[i]].b-max(a[fb[i]].a,a[fb[i]].c)]++;
			bool p=false;
			for(int i=0;i<=20000;i++)
			{
				for(int j=1;j<=f[i];j++)
				{
					ans-=i;
					kb--;
					if(kb<=n/2)
					{
						p=true;
						break;
					}
				}
				if(p) break;
			}
		}
		else if(kc>n/2)
		{
			memset(f,0,sizeof(f));
			for(int i=1;i<=kc;i++) f[a[fc[i]].c-max(a[fc[i]].a,a[fc[i]].b)]++;
			bool p=false;
			for(int i=0;i<=20000;i++)
			{
				for(int j=1;j<=f[i];j++)
				{
					ans-=i;
					kc--;
					if(kc<=n/2)
					{
						p=true;
						break;
					}
				}
				if(p) break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
