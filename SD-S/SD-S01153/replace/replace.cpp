#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
const int N=2e5+10;
const int P=1e9+7;

int n,q,ans,sum;
int sz[N],p[N][3];
string t[3],s[N][3];

void solve1()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<t[0].size()-sz[i]+1;j++)
		{
			bool f=1;
			for(int k=0;k<sz[i];k++)
				if(s[i][0][k]!=t[0][j+k])
				{
					f=0;
					break;
				}
			if(f)
			{
				string tmp=t[0];
				for(int k=0;k<sz[i];k++)tmp[j+k]=s[i][1][k];
//				cout<<tmp<<'\n';
				if(tmp==t[1])
				{
					ans++;
					break;
				}
			}
		}
	}
}

void solve2()
{
	int pt[3]={0,0};
	for(int i=0;i<2;i++)for(int j=0;j<t[i].size();j++)if(t[i][j]=='b')pt[i]=j;
	int d=pt[0]-pt[1];
	for(int i=1;i<=n;i++)
	{
		if(p[i][0]-p[i][1]==d&&p[i][0]>=pt[0]&&sz[i]+pt[0]-p[i][0]<=t[0].size())
			ans++;
//		cout<<i<<endl;
	}
}

signed main()
{
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		sz[i]=s[i][1].size();
		sum+=sz[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=0;k<2;k++)
			for(int j=0;j<sz[i];j++)
				if(s[i][k][j]=='b')p[i][k]=j;
//		cout<<p[i][0]<<" "<<p[i][1]<<'\n';
	}
	while(q--)
	{
		ans=0;
		cin>>t[0]>>t[1];
		if(sum<=2000)solve1();
		else solve2();
		cout<<ans<<'\n';
	}
	return 0;
}

