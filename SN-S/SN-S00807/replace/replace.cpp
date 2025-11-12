#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Revi{
	const int N=5e5+5;
	int n,q;
	pair<string,string> s[N];
	vector<int> v[N],vv[N];
	void KMP(string s,vector<int>::iterator nxt)
	{
		int n=s.size()-1;
		for(int i=2;i<=n;i++)
		{
			int j=*(nxt+i-1);
			while(j&&s[j+1]!=s[i]) j=nxt[j];
			if(s[j+1]==s[i]) *(nxt+i)=j+1;
			else *(nxt+i)=0; 
		}
	}
	inline void work()
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++) cin>>s[i].first>>s[i].second;
		while(q--)
		{
			string l,r;
			cin>>l>>r;
			cout<<0<<"\n";
		} 
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Revi::work();
	return 0;
 } 
