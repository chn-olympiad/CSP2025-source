#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<int> v;
string s[200005][2];
vector<int> nxt[200005][2];
string pre[200005],lst[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i][0] >> s[i][1];
		s[i][0]=" "+s[i][0];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=s[i][0].size();j++) nxt[i][0].push_back(0);
		int now=0;
		for(int j=2;j<s[i][0].size();j++)
		{
			while(now&&s[i][0][j]!=s[i][0][now+1]) now=nxt[i][0][now];
			if(s[i][0][j]==s[i][0][now+1]) now++;
			nxt[i][0][j]=now;
		}
		for(int j=0;j<=s[i][1].size();j++) nxt[i][1].push_back(0);
		now=0;
		for(int j=2;j<s[i][1].size();j++)
		{
			while(now&&s[i][1][j]!=s[i][1][now+1]) now=nxt[i][1][now];
			if(s[i][1][j]==s[i][1][now+1]) now++;
			nxt[i][1][j]=now;
		}
	}
	while(q--)
	{
		string t1,t2; cin >> t1 >> t2;
		if(t1.size()!=t2.size()) {cout << "0\n"; continue;}
		int l=t1.size();
		v.clear();
		for(int i=0;i<l;i++)
			if(t1[i]!=t2[i]) v.push_back(i);
		bool flag=0;
		for(int i=1;i<v.size();i++)
			if((v[i]-v[i-1])>1) {flag=1; break;}
		if(flag) {cout << "0\n"; continue;}
		t1=" "+t1; t2=" "+t2;
		pre[0]=" "; lst[l+1]="";
		for(int i=1;i<t1.size();i++) pre[i]=pre[i-1]+t1[i];
		for(int i=t1.size()-1;i>=1;i--) lst[i]=t1[i]+lst[i+1];
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int now=0;
			vector<int> t; t.clear();
			for(int j=1;j<t1.size();j++)
			{
				while(now&&t1[j]!=s[i][0][now+1]) now=nxt[i][0][now];
				if(t1[j]==s[i][0][now+1]) now++;
				if(now==s[i][0].size()-1)
				{
					t.push_back(j-(s[i][0].size()-1)+1);
					now=nxt[i][0][now];
				}
			}
			for(int j=0;j<t.size();j++)
			{
				int l=t[j]-1,r=t[j]+(s[i][0].size()-1);
				string num=pre[l]+s[i][1]+lst[r];
				if(num==t2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
