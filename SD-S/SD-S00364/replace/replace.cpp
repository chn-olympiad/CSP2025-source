#include<bits/stdc++.h>
#define i64 long long
#define u64 unsigned long long
#define prs " \n"
#define iinf 0x3f3f3f3f
using namespace std;
const int N=2e5+10;
int n,q,bt[N];
string s[N][2],t[N][2];
int main()
{
 	freopen("replace.in","r",stdin);
 	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++)
		cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		for(int j=0;j<t[i][0].size();j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j+s[k][0].size()>t[i][0].size())
					continue;
				if(t[i][0].substr(j,j+s[k][0].size())==s[k][0])
				{
					string t1=t[i][0];
					t1.replace(j,j+s[k][0].size(),s[k][1]);
					if(t1==t[i][1]) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

