#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define db long double
#define Pii pair<int,int>
#define Pss pair<string,string>
#define fi first
#define se second

using namespace std;
const int N=2e5+10;

int n,q,cnt; string s1,s2,t1,t2;
map<Pss,vector<Pss>> mp;

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>s1>>s2;
		int l=0,r=s1.size()-1;
		while(s1[l]==s2[l]) ++l;
		while(s1[r]==s2[r]) --r;
		if(l>r) continue;
		mp[{s1.substr(l,r-l+1),s2.substr(l,r-l+1)}].push_back
		({s1.substr(0,l),s1.substr(r+1,s1.size()-r-1)});
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {cout<<"0\n"; continue;}
		int l=0,r=t1.size()-1;
		while(t1[l]==t2[l]) ++l;
		while(t1[r]==t2[r]) --r;
		int ans=0;
		Pss nw={t1.substr(l,r-l+1),t2.substr(l,r-l+1)};
		Pss la={t1.substr(0,l),t1.substr(r+1,t1.size()-r-1)};
		for(auto a:mp[nw])
		{
			int fl=1;
			if(a.fi.size()>la.fi.size()) continue;
			else
			{
				for(int i=0;i<a.fi.size();++i)
					if(a.fi[i]!=la.fi[i+la.fi.size()-a.fi.size()]) {fl=0; break;}
			}
			if(a.se.size()>la.se.size()) continue;
			else
			{
				for(int i=0;i<a.se.size();++i)
					if(a.se[i]!=la.se[i]) {fl=0; break;}
			}
			if(fl) ++ans;
		}
		cout<<ans<<"\n";
	}
	return 0;
}