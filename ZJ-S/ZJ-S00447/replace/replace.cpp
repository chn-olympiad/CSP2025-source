#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<pair<string,string> >vp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		vp.push_back(make_pair(s1,s2));
	}
	while(q--)
	{
		string t1,t2,t3,t4;
		int ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=t1.length();i++)
		{
			if(t1[i]!=t2[i])t3+=t1[i],t4+=t2[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
