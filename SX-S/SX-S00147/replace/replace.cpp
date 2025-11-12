#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N],b[N];
int ida[N],idb[N];
int n,q;
void _main()
{
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--)
	{
		string s,t;
		cin>>s>>t;
		int ans=0;
		if(s.length()==t.length())
		{
			for(int i=1;i<=n;i++) 
			{
				for(int j=0;j<(int)s.length()-(int)a[i].length()+1;j++)
				{
					string subs=s.substr(j,a[i].length());
					string subt=t.substr(j,a[i].length());
					string subss=s.substr(j+a[i].length());
					string subtt=t.substr(j+a[i].length());
					if(subs==a[i]&&subt==b[i]&&subss==subtt) ans++;
					if(t[j]!=s[j]) break;
				}
			}	
		}
		cout<<ans<<endl;
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	if(n<=100&&q<=100) _main();
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i].length();j++) 
		{
			if(a[i][j]=='b') ida[i]=j;
		}
		for(int j=0;j<b[i].length();j++) 
		{
			if(b[i][j]=='b') idb[i]=j;
		}
	}
	while(q--)
	{
		string s,t;
		cin>>s>>t;
		int ans=0;
		if(s.length()==t.length())
		{
			int ids,idt;
			for(int j=0;j<s.length();j++) 
			{
				if(s[j]=='b') ids=j;
			}
			for(int j=0;j<t.length();j++) 
			{
				if(t[j]=='b') idt=j;
			}
			for(int i=1;i<=n;i++) 
			{
				if(ids>=ida[i]&&idt>=idb[i]&&ids-idt==ida[i]-idb[i]&&s.length()-ids>=a[i].length()-ida[i]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
