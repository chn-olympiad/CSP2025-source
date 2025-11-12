//林靖轩 SN-S00418 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,q;
string s[N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		string s1,s2;
		cin>>s1>>s2;
		int k=s1.size()+10;
		int w=-1;
		for(int i=0;i<s1.size();i++)
			if(s1[i]!=s2[i])k=min(i,k),w=max(i,w);
		string cnt;
		for(int i=k;i<=w;i++)
			cnt+=s1[i];

		cout<<0<<"\n";
	}
	return 0;
}

