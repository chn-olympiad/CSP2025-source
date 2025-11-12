#include<bits/stdc++.h>

using namespace std;
#define ull unsigned long long 

const int N=1e6+15;
const int p=13331;

string s1[N],s2[N];
ull h1[N],h2[N];
ull pre1[N],pre2[N];
int n,q,res;
string t1,t2;

bool check(int loc,string s1,string s2)
{
//	cout<<loc<<" "<<s1<<" "<<s2<<endl;
	int len=s1.size();
	int now=0;
	for(int i=loc;i<=loc+len-1;i++)
	{
		if(s1[now]!=t1[i])
		{
//			cout<<s1[now]<<" "<<t1[i]<<endl;
			return 0;
		}
		now++;
	}
	
	int len2=s2.size();
	int rl=t1.size();
	int l=t2.size();
	if(rl-len+len2!=l) return 0;
	now=0;
//	cout<<loc<<" "<<s1<<" "<<s2<<endl;
	for(int i=0;i<loc;i++)
	{
		if(t1[i]!=t2[now]) return 0;
		now++;
	}
	for(int i=0;i<len2;i++)
	{
		if(s2[i]!=t2[now]) return 0;
		now++;
	}
	for(int i=loc+len;i<rl;i++)
	{
		if(t1[i]!=t2[now]) return 0;
		now++;
	}
	return 1;
}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		for(int j=0;j<(signed)s1[i].size();j++)
			h1[i]=h1[i]*13331+(int)s1[i][j];
		for(int j=0;j<(signed)s2[i].size();j++)
			h2[i]=h2[i]*13331+(int)s2[i][j];
	}
	while(q--)
	{
		cin>>t1>>t2;
		int ans=0;
		int len=t1.size();
		for(int i=1;i<=n;i++)
		{
			int len1=s1[i].size();
			for(int j=0;j<len;j++)
			{
				if(len1+j-1>=len) break; 
				if(check(j,s1[i],s2[i])) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/