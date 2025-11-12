#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+50;
int t;
int n;
struct node
{
	int a,b,c;
	int mx;
	int mxc;
	int bj;
}s[N];
bool cmp(node a,node b)
{
	return a.mxc<b.mxc;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a>>s[i].b>>s[i].c;
			int b[4];
			b[1]=s[i].a,b[2]=s[i].b,b[3]=s[i].c;
			sort(b+1,b+4);
			s[i].mx=b[3];
			s[i].mxc=b[3]-b[2];
		}
		int ans=0;
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++)
		{
			ans+=s[i].mx;
			if(s[i].mx==s[i].a)
			{
				x++;
				s[i].bj=1;
			}
			else if(s[i].mx==s[i].b)
			{
				y++;
				s[i].bj=2;
			}
			else 
			{
				z++;
				s[i].bj=3;
			}
		}
		if(x<=n/2&&y<=n/2&&z<=n/2)cout<<ans<<endl;
		else if(x>n/2||y>n/2||z>n/2)
		{
			sort(s+1,s+n+1,cmp);
			int k=max({x,y,z});
			int fl;
			if(k==x)fl=1;
			else if(k==y)fl=2;
			else fl=3;
			for(int i=1;i<=n&&k>n/2;i++)
			{
				if(s[i].bj==fl)
				{
					ans-=s[i].mxc;
					k--;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
//贪心，做了1.5h，感觉是人均题，唉 
