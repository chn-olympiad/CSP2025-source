#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2,s3,s4;
map <string,string> mp;
int ans;
string sub(string s,int l,int r)
{
	if(r<=l) return "";
	string ans="";
	for(int i=l;i<r;i++) ans+=s[i];
	return ans;
}
int nxt[5000005];
void qwq(string b)
{
	int j=0;
	b=" "+b;
	for(int i=2;i<b.length();i++)
	{
		while(j&&b[i]!=b[j+1]) j=nxt[j];
		if(b[i]==b[j+1]) j++;
		nxt[i]=j;
	}
}
void kmp(string a,string b)
{
	int j=0;
	qwq(b);
	a=" "+a;
	b=" "+b;
	for(int i=1;i<a.length();i++)
	{
		while(j&&a[i]!=b[j+1]) j=nxt[j];
		if(a[i]==b[j+1]) j++;
		if(j==b.length()-1)
		{
			string anss=sub(s1,0,i-j)+s4+sub(s1,i-j+s3.length(),s1.length());
			if(anss==s2) ans++;
			j=nxt[j];
		}
	}
}
int main()
{
//	system("fc replace.out replace3.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1>>s2,mp[s1]=s2;
	while(q--)
	{
		cin>>s1>>s2;
		ans=0;
		for(auto qwq:mp)
		{
			s3=qwq.first;
			s4=qwq.second;
			kmp(s1,s3);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

