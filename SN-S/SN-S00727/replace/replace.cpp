//SN-S00727  menkeming xi'anfulunzhongxue
#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,q;
map<string,string>mp;
string s1[200010],s2[200010];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i],mp[s1[i]]=s2[i];
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		int len1=t1.size(),len2=t2.size(),st=1e6,en=-1;
		if(len1!=len2)
			cout<<"0\n";
		else{
			int ans=0;
			for(int i=0;i<len1;i++)
				if(t1[i]!=t2[i])
					st=min(i,st),en=max(i,en);
			for(int i=0;i<=st;i++)
				for(int j=en-1;j<len1;j++)
					if((mp[t1.substr(i,j-i+1)]!="")&&t1.substr(0,i)+mp[t1.substr(i,j-i+1)]+t1.substr(j+1,len1-j-1)==t2)
						ans++;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
