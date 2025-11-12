//SN-S00636 蔡铭禹 西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string sl[10010],so[10010];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>sl[i]>>so[i];
	}
	string tl,to;
	while(q--)
	{
		int ans=0;
		cin>>tl>>to;
		for(int i=1;i<=n;i++)
		{
			int tp=sl[i].size();
			int tt=tl.size()-tp+1;
			for(int j=0;j<tt;j++)
			{
				if(tl.substr(j,tp)==sl[i]) 
				{
					string s=tl.substr(0,j)+so[i]+tl.substr(j+tp,tl.size()-tp-j);
					if(s==to)
					{
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
