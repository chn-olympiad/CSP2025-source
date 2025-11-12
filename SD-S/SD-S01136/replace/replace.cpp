#include<bits/stdc++.h>
#define int long long
using namespace std;

string s[300006][2];
int n;
int cs[300006];
void solve()
{
	string t1,t2;
	cin>>t1>>t2;
	int ans=0;
	for(int i=0;i<t1.size();i++)
	{
		for(int j=i;j<t1.size();j++)
		{
			string t="";
			string x="";
			string y="";
			for(int k=0;k<t1.size();k++) 
			{
				if(k<i) x+=t1[k];
				else if(k>j) y+=t1[k];
				else t+=t1[k];
			}
			for(int ie=1;ie<=n;ie++)
			{
				if(t==s[ie][0]) 
				{
					string tt=x+s[ie][1]+y;
					if(t2==tt) ans++;
				}
			}
		}
	}
	cout<<ans<<'\n';
}

signed main()
{
    freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	int sum=0;
	for(int i=1;i<=n;i++) sum+=s[i][0].size();
	sum*=2;
	sum=sum*sum;
	sum*=n;
	sum*=q;
	if(sum<500000000) while(q--) solve();
	else
	{
		for(int i=1;i<=n;i++)
		{
			int id1,id2;
			for(int j=0;j<s[i][0].size();j++) if(s[i][0][j]=='b') id1=j;
			for(int j=0;j<s[i][1].size();j++) if(s[i][1][j]=='b') id2=j;
			cs[i]=max(id1,id2)-min(id1,id2)-1;
		}
		while(q--)
		{
			int ans=0;
			string tt1,tt2;
			cin>>tt1>>tt2;
			int id1,id2;
			for(int j=0;j<tt1.size();j++) if(tt1[j]=='b') id1=j;
			for(int j=0;j<tt2.size();j++) if(tt2[j]=='b') id2=j;
			int tcs=max(id1,id2)-min(id1,id2)-1;
			for(int i=1;i<=n;i++)
			{
				if(tcs==cs[i]) ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

