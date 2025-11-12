#include<bits/stdc++.h>
#define int long long
namespace FastIO
{
	inline int read()
	{
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-') f^=1;
			c=getchar();
		} 
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+(c^48);
			c=getchar();
		}
		return f?x:~x+1; 
	}
	inline void write(int x)
	{
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar(x%10^48);
	}
	inline void spaceput(int x)
	{
		write(x);putchar(' ');
	}
	inline void output(int x)
	{
		write(x);putchar('\n');
	}
} 
using namespace std;
using namespace FastIO;
constexpr int mod1=998244353;
constexpr int mod2=1e9+7;
constexpr int bas1=19991;
constexpr int bas2=13331;
#define s1 s_1
#define s2 s_2
#define t1 t_1
#define t2 t_2
#define mp1 mp_1
#define mp2 mp_2
#define now1 now_1
#define now2 now_2
int n,q;
//map<string,int> mp1,mp2;
map<string,string> mp1,mp2;
inline int geth1(string x)
{
	int len=x.length();
	int res=0;
	for(int i=0;i<len;i++) res=(res*bas1+x[i])%mod1;
	return res;
}
inline int geth2(string x)
{
	int len=x.length();
	int res=0;
	for(int i=0;i<len;i++) res=(res*bas2+x[i])%mod2;
	return res;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		if(mp1[s1]=="") mp1[s1]=s2;
		if(mp2[s2]=="") mp2[s1]=s2;
	}
	while(q--){
		string t1,t2;cin>>t1>>t2;
		int len1=t1.length(),len2=t2.length();
		int ans=0;
		if(len1!=len2) cout<<0<<'\n';
		else{
			int l=0,r=len1-1;
			for(l=0;l<len1;l++){
				if(t1[l]!=t2[l]) break;
			}
			for(r=len1-1;r>0;r--){
				if(t1[r]!=t2[r]) break;
			}
//			cout<<l<<' '<<r<<'\n';
			for(int i=0;i<=l;i++){
				string p="",q="";
//				int now1=0,now2=0;
				for(int j=i;j<r;j++){
					p+=t1[j];q+=t2[j];
//					now1=(now1*bas1+t2[j])%mod1;
//					now2=(now2*bas2+t2[j])%mod2;
				}
				for(int j=r;j<len1;j++){
					p+=t1[j];q+=t2[j];
//					cout<<p<<' ';
//					now1=(now1*bas1+t2[j])%mod1;
//					now2=(now2*bas2+t2[j])%mod2;
					if(mp1[p]==q&&mp2[p]==q) ans++;
				}
			}
			cout<<ans<<'\n';
		}
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
ans:
2
0
*/
