#include<bits/stdc++.h>
#define int long long
#define signed bool __End;signed
using namespace std;
bool __Begin;
namespace _IO{inline int read(){int f=1,res=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){res=res*10+(ch-'0');ch=getchar();}return f*res;}void write(int x){if(x<0){putchar('-');write(-x);}else if(x<=9){putchar(x+'0');}else{write(x/10);putchar(x%10+'0');}return;}}
namespace _Min{int Min(int x,int y){return x<y?x:y;}int Max(int x,int y){return x>y?x:y;}}

using namespace _IO;
using namespace _Min;

const int mod=1e9+7,base=131;
int n,q,pw[2000005];
int Add(int x,int y){
	return (x+y)%mod;
}
int Mul(int x,int y){
	return 1ll*x*y%mod;
}
int Del(int x,int y){
	return x<y?x-y+mod:x-y;
}
int qpow(int x,int y){
	int res=1;
	while(y>0){
		if(y&1){
			res=Mul(res,x);
		}
		x=Mul(x,x);
		y/=2;
	}
	return res;
}
struct HASH{
	string s;
	int len,h[1005];
	void hash(){
		len=s.length();
		for(int i=1;i<=len;i++){
			h[i]=Add(Mul(h[i-1],base),s[i-1]-'a'+1);
		}
		return;
	}
	int query(int l,int r){
		if(l>r)return 0;
		return Del(h[r],Mul(h[l-1],pw[r-l+1]));
	}
}s1[1005],s2[1005],t1,t2;
map<pair<int,int>,int>mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	pw[0]=1;
	for(int i=1;i<=2000000;i++){
		pw[i]=Mul(pw[i-1],base);
	}
	for(int i=1;i<=n;i++){
		cin>>s1[i].s>>s2[i].s;
		s1[i].hash();
		s2[i].hash();
		mp[{s1[i].h[s1[i].len],s2[i].h[s2[i].len]}]++;
	}
	for(int i=1;i<=q;i++){
		cin>>t1.s>>t2.s;
		t1.hash(),t2.hash();
		int ans=0;
		for(int l=1;l<=t1.len;l++){
			for(int r=l;r<=t1.len;r++){
				if(t1.query(1,l-1)==t2.query(1,l-1)&&t1.query(r+1,t1.len)==t2.query(r+1,t2.len)){
					ans+=mp[{t1.query(l,r),t2.query(l,r)}];
				}
			}
		}
		write(ans),puts("");
	}
//	cerr<<"\n"<<(clock())<<"ms "<<(((&__Begin)-(&__End))>>20)<<"MB\n";
	return 0;
}
