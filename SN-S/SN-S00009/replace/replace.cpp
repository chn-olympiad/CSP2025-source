#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100005][2];
string t[2];
int d[100005],w[100005];
int f=1;
void solve()
{
	int ans=0;
	cin>>t[0]>>t[1];
	if(f)
	{
		int now=0,ww,hh;
		for(int i=0;i<t[0].size();i++)
		{
			if(t[0][i]=='b') 
			{
				now+=i;
				ww=i;
			}
			if(t[1][i]=='b')
			{
				now-=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(now==d[i] && t[0].size()>=s[i][0].size() && ww>=w[i] && t[0].size()-ww>=s[i][0].size()-w[i]) ans++;
		}
		cout<<ans<<endl;
		return;
	}
	int l=0x3f3f3f3f,r=0;
	for(int i=0;i<t[0].size();i++)
	{
		if(t[0][i]!=t[1][i]) 
		{
			l=min(l,i);
			r=max(r,i);
		}
	}
	for(int i=0;i<=l;i++)
	{
		string c1=t[0].substr(i,r-i);
		string c2=t[1].substr(i,r-i);
		for(int len=r-i+1;len<=t[0].size()-i;len++)
		{
//			cout<<c1<<' '<<c2<<endl;
			int j=i+len-1;
			c1+=t[0][j];
			c2+=t[1][j];
			for(int k=1;k<=n;k++)
			{
				if(s[k][0]!=c1) continue;
				if(s[k][1]!=c2) continue;
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=n;i++)
	{
		int cnt1=0,cnt2=0;
		for(int j=0;j<s[i][0].size();j++)
		{
			if(s[i][0][j]!='a' && s[i][0][j]!='b')
			{
				f=0;
				break;
			}
			if(s[i][0][j]=='b')
			{
				d[i]+=j;
				w[i]=j;
				cnt1++;
			}
			if(s[i][1][j]!='a' && s[i][1][j]!='b')
			{
				f=0;
				break;
			}
			if(s[i][1][j]=='b')
			{
				d[i]-=j;
				cnt2++;
			}
		}
		if(cnt1!=1 || cnt2!=1)
		{
			f=0;
			break;
		} 
		if(f==0) break;
	}
	while(q--)
	{
		solve();
	}
	return 0;
}
