#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
string s1[N], s2[N];
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		string st, to;
		cin>>st>>to;
		if(st.size()!=to.size())
		{
			cout<<0<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int len=s1[i].size();
			for(int j=0;j<st.size()+1-len;j++)
			{
				if(st.substr(j, len)==s1[i])
				{
					string tmp=st;
					tmp.replace(j, len, s2[i]);
					if(tmp==to) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
