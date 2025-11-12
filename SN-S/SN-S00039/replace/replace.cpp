#include<bits/stdc++.h>
#define nxt1 (trie1.t[p1][F(t1[j])])
#define nxt2 (trie2.t[p2][F(t2[j])])
using namespace std;
const int N=5e6+5;
int n,q,i,l;
string s1,s2,t1,t2;
int F(char s){return s-'a';}
struct trie
{
	int t[N][27],idx=0;
	vector<int> cnt[N];
	void ins(string s)
	{
		int p=0;
		for(int ii=1;ii<s.length();ii++)
		{
			int u=F(s[ii]);
			if(!t[p][u]) t[p][u]=++idx;
			p=t[p][u];
			if(ii==s.length()-1) cnt[p].push_back(i);
		}
	}
}trie1,trie2;
int check()
{
	int ans=0;
	for(i=1;i<=l;i++)
	{
		int p1=0,p2=0,j=i,res=0;
		for(;;j++)
		{
			if(!nxt1||!nxt2) break;
			p1=nxt1,p2=nxt2;
			for(int r1=0;r1<(int)trie1.cnt[p1].size();r1++) for(int r2=0;r2<(int)trie2.cnt[p2].size();r2++)
			{
				if(trie1.cnt[p1][r1]==trie2.cnt[p2][r2]) res++;
			}
		}
		for(;j<=l;j++) if(t1[j]!=t2[j]) res=0;
		ans+=res;
		if(t1[i]!=t2[i]) break;
	}
	return ans;
} 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		s1=" "+s1,s2=" "+s2;
		trie1.ins(s1);
		trie2.ins(s2);
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) 
		{
			cout<<0<<'\n';
			continue;
		}
		l=t1.size();
		t1=" "+t1,t2=" "+t2;
		cout<<check()<<'\n';
	}
	return 0;
}
