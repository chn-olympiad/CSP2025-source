#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
string s1[200005],s2[200005],qs1,qs2;
bool vis[200005];
signed main()
{
//	system("fc replace3.ans replace.out");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		int cnt=0;
		cin>>qs1>>qs2;
		for(int i=1;i<=n;i++)
			if(qs1.find(s1[i])!=-1)
			{
				string ss=qs1;
				int k=ss.find(s1[i]);
				ss.erase(k,s1[i].size());
				ss.insert(k,s2[i]);
				if(ss==qs2) cnt++;
			}
		cout<<cnt<<endl;
	}
	return 0;
}
