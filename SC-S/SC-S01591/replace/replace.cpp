#include <bits/stdc++.h>
#include <bits/extc++.h>
#define pii pair<int,int>
#define pb emplace_back
#define mk make_pair
#define ll long long
#define fi first
#define se second
#ifdef int
#define inf ((1e18)+10)
#else 
#define inf ((1e9)+10)
#endif
//#define ls (now<<1)
//#define rs (now<<1|1)
//#define mid ((l+r)>>1)
using namespace std;
using namespace __gnu_pbds;
bool Mst;
const int Max=5e6+10;
const int mod=998244353;
const double eps=1e-9;


inline int read(){
	int res=0,v=1;
	char c=getchar();
	while(c<'0'||c>'9'){v=(c=='-'?-1:1);c=getchar();}
	while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
	return res*v;
}

const int Bas=211;
const int Bas1=73;
const int Bas2=97;
ll bas[Max];
gp_hash_table<ll,int>vis,val,num,id;
struct po{
	ll Val;int st,ed,len,id;
	po(ll Val=0,int st=0,int ed=0,int len=0,int id=0):Val(Val),st(st),ed(ed),len(len),id(id){;}
	bool operator <(const po a)const{return len<a.len;}
};
vector<po>vv[Max];
int n,q;char s[Max],t[Max];
string S[Max],T[Max];

bool Med;
signed main(){
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	n=read();q=read();bas[0]=1;int idx=0;
	for(int i=1;i<Max;++i)bas[i]=bas[i-1]*Bas%mod;
	for(int i=1;i<=n;++i){
		string s,t;
		cin>>s;cin>>t;
		s=' '+s;t=' '+t;
		S[i]=s;T[i]=t;
		int len=s.length()-1;
		int ed=0,st=0;
		for(int j=len;j>=1;--j){
			if(s[j]!=t[j]){
				ed=j;
				break;
			}
		}
		if(!ed)continue;
		for(int j=1;j<=ed;++j){
			if(s[j]!=t[j]){
				st=j;
				break;
			}
		}
//		cout << st << ' ' << ed << "=======\n";
		ll Val=0;
		for(int j=st;j<=ed;++j){
			Val=(Val*Bas%mod+s[j]-'a'+1)%mod;
			Val=(Val*Bas%mod+t[j]-'a'+1)%mod;
		}
//		cout << Val << '\n';
		for(int j=st-1;j>=1;--j){
			Val=(Val*Bas1%mod+s[j]-'a'+1)%mod;
		}
		
		if(!id[Val])id[Val]=++idx;
		vv[id[Val]].pb(po(Val,st,ed,len-ed,i));
	}
	
	for(int z=1;z<=idx;++z){
		sort(vv[z].begin(),vv[z].end());
//		cout << z << "---\n";
		for(auto res:vv[z]){
			ll Val=res.Val;int ed=res.ed,i=res.id;
			string s=S[i],t=T[i];int len=s.length()-1;
//			cout << i << '\n';
			int Res=0;
			for(int j=ed;j<len;++j){
				if(j!=ed)Val=(Val*Bas2%mod+s[j]-'a'+1)%mod;
				vis[Val]=1;Res+=num[Val];
			}
			if(ed!=len)Val=(Val*Bas2%mod+s[len]-'a'+1)%mod;
			vis[Val]=1;val[Val]+=Res+1;num[Val]++;
		}
	}
	
	
	
	
	
	for(int j=1;j<=q;++j){
		scanf("%s",s+1);scanf("%s",t+1);
		
//		if(j!=101)continue;
		int len=strlen(s+1);
		int ed=0,st=0,ans=0;
		for(int j=len;j>=1;--j){
			if(s[j]!=t[j]){
				ed=j;
				break;
			}
		}
		if(!ed)continue;
		for(int j=1;j<=ed;++j){
			if(s[j]!=t[j]){
				st=j;
				break;
			}
		}
		ll Val=0;
		for(int j=st;j<=ed;++j){
			Val=(Val*Bas%mod+s[j]-'a'+1)%mod;
			Val=(Val*Bas%mod+t[j]-'a'+1)%mod;
		}
//		cout << Val << '\n';
		for(int j=st;j>=1;--j){
			if(j!=st)Val=(Val*Bas1%mod+s[j]-'a'+1)%mod;
			ll v=Val;
			for(int j=ed;j<=len;++j){
				
				if(j!=ed)v=(v*Bas2%mod+s[j]-'a'+1)%mod;
				if(!vis[v])break;
				ans+=num[v];
			}
//			ans+=val[v];
			
		}
		cout << ans << "\n";
	}
	
	
//	cerr << "Time: "<< clock()/1000.0 << "s\n";
//	cerr << "Me: "<< abs(&Mst-&Med)/1048576.0 << "MB\n";
	return 0;
}
/*
嘟嘟嘟，会 O(n\sqrt n) 的东西。
先考虑特殊性质 B。
t=x+y+z
s=a+b+c
要求 y=b 且 a 是 x 的后缀，c 是 z 的前缀
考虑hash，四元组 (y,y`,a,c)，来描述
#include <bits/stdc++.h>
#include <bits/extc++.h>
#define pii pair<int,int>
#define pb emplace_back
#define mk make_pair
#define ll long long
#define fi first
#define se second
#ifdef int
#define inf ((1e18)+10)
#else 
#define inf ((1e9)+10)
#endif
//#define ls (now<<1)
//#define rs (now<<1|1)
//#define mid ((l+r)>>1)
using namespace std;
using namespace __gnu_pbds;
bool Mst;
const int Max=2e5+10;
const int mod=998244353;
const double eps=1e-9;


inline int read(){
int res=0,v=1;
char c=getchar();
while(c<'0'||c>'9'){v=(c=='-'?-1:1);c=getchar();}
while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+(c^48);c=getchar();}
return res*v;
}

const int Bas=211;
ll bas[Max];
gp_hash_table<ll,int>vis,val,num;
int n,q;char s[Max],t[Max];


ll v[Max];


bool Med;
signed main(){
n=read();q=read();bas[0]=1;
for(int i=1;i<Max;++i)bas[i]=bas[i-1]*Bas%mod;
for(int i=1;i<=n;++i){
scanf("%s",s+1);
scanf("%s",t+1);
int len=strlen(s+1);
int ed=0,st=0;
for(int j=len;j>=1;--j){
if(s[j]!=t[j]){
ed=j;
break;
}
}
if(!ed)continue;
for(int j=1;j<=ed;++j){
if(s[j]!=t[j]){
st=j;
break;
}
}
//		cout << st << ' ' << ed << "=======\n";
ll Val=0;
for(int j=st;j<=ed;++j){
Val=(Val*Bas%mod+s[j]-'a'+1)%mod;
Val=(Val*Bas%mod+t[j]-'a'+1)%mod;
}
//		cout << Val << '\n';
for(int j=st-1;j>=1;--j){
Val=(Val*Bas%mod+s[j]-'a'+1)%mod;
}
int Res=0;
for(int j=ed;j<len;++j){
if(j!=ed)Val=(Val*Bas%mod+s[j]-'a'+1)%mod;
vis[Val]=1;Res+=num[Val];
}
if(ed!=len)Val=(Val*Bas%mod+s[len]-'a'+1)%mod;
vis[Val]=1;val[Val]+=Res+1;num[Val]++;
}
//	exit(0);
for(int j=1;j<=q;++j){
scanf("%s",s+1);scanf("%s",t+1);
int len=strlen(s+1);
int ed=0,st=0,ans=0;
for(int j=len;j>=1;--j){
if(s[j]!=t[j]){
ed=j;
break;
}
}
if(!ed)continue;
for(int j=1;j<=ed;++j){
if(s[j]!=t[j]){
st=j;
break;
}
}
ll Val=0;
for(int j=st;j<=ed;++j){
Val=(Val*Bas%mod+s[j]-'a'+1)%mod;
Val=(Val*Bas%mod+t[j]-'a'+1)%mod;
}
v[0]=0;
for(int i=ed+1;i<=len;++i){v[i-ed]=(v[i-1-ed]*Bas%mod+s[i]-'a'+1)%mod;}
for(int j=st;j>=1;--j){
if(j!=st)Val=(Val*Bas%mod+s[j]-'a'+1)%mod;
int l=0,r=len-ed,Ans=0;
while(l<=r){
int mid=(l+r)>>1;
ll val=(Val*bas[mid]%mod+v[mid])%mod;
if(vis[val]!=0){l=mid+1,Ans=mid;}
else r=mid-1;
}
ll res=(Val*bas[Ans]%mod+v[Ans])%mod;
ans+=val[res];
}
cout << ans << '\n';
}


//	cerr << "Time: "<< clock()/1000.0 << "s\n";
//	cerr << "Me: "<< abs(&Mst-&Med)/1048576.0 << "MB\n";
return 0;
}
嘟嘟嘟，会 O(n\sqrt n) 的东西。
先考虑特殊性质 B。
t=x+y+z
s=a+b+c
要求 y=b 且 a 是 x 的后缀，c 是 z 的前缀
考虑hash，四元组 (y,y`,a,c)，来描述
*/