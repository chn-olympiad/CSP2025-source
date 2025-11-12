#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,ans;
string s[200005][3];
string t1,t2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)	cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		if(t1==t2)	ans++;
		for(int i=0;i<t1.size()&&i<t2.size();i++)
		{
			if(t1.substr(0,i)!=t2.substr(0,i))	break;
//			cout<<t2.substr(i,t2.size()-i)<<"\n";
			for(int j=1;j<=n;j++)
			{
				if(i+s[j][1].size()>t1.size()||t1.substr(i,s[j][1].size())!=s[j][1])	continue;
				ans+=(t2.substr(i,t2.size()-i)==s[j][2]+t1.substr(s[j][2].size()+i,t1.size()-i-s[j][2].size()));
//				cout<<j<<':'<<s[j][2]+t1.substr(s[j][2].size()+i,t1.size()-i-s[j][2].size())<<" ";
			}
//			cout<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}