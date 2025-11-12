#include<bits/stdc++.h>
#define FOR(i,j,k) for(int i=(j);i<=(k);++i)
#define NFOR(i,j,k) for(int i=(j);i>=(k);--i)
#define fst first
#define sec second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3fll;
int read()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1,c=getchar();}
	while(c>='0'&&c<='9') {s=(s<<1)+(s<<3)+c-'0';c=getchar();}
	return s*w;
}
void file(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
namespace modi
{
	const int mod=998244353;
	ll mulmod(ll a,ll b) {return 1ll*a*b%mod;}
	ll addmod(ll a,ll b) {return (a+b)%mod;}
	ll delmod(ll a,ll b) {return (a-b+mod)%mod;}
}
using namespace modi;
const int N=2e5+5;

int n,q;
string s1[N],s2[N];

int chk(string t1,string t2)
{
	int len=t1.size(),ret=0;
	FOR(i,1,n) 
	{
		bool flg=1;
		if(s1[i].size()>len) continue;
		FOR(l,1,len-s1[i].size()+1)
		{	
			bool flg=1;
			FOR(j,1,s1[i].size())
			{
				if(s1[i][j-1]!=t1[l+j-2]||s2[i][j-1]!=t2[l+j-2]) flg=0;
			}
			if(flg)
			{
				FOR(j,l+s1[i].size(),len) if(t1[j-1]!=t2[j-1]) flg=0;
				FOR(j,1,l-1) if(t1[j-1]!=t2[j-1]) flg=0;
				if(flg)
				ret++/*,printf("%d %d\n",l,i)*/;
			} 
		}
	}
	return ret;
}

int main()
{
	file("replace");
	n=read();q=read();
	FOR(i,1,n) cin>>s1[i]>>s2[i];
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		printf("%d\n",chk(t1,t2));
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

*/
