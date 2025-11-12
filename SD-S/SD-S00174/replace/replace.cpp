#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#define ll long long
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define rop(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a,b) for(int i=(a);i>(b);--i)
using namespace std;
int iread(){int x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
ll lread(){ll x=0,y=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') y=-1;c=getchar();}while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+(c^'0');c=getchar();}return x*y;}
const int N=5e6+500;
const int mod=998244353;
const int D=311;
ll pw[N];
void init(int n){
	pw[0]=1;
	FOR(i,1,n){
		pw[i]=pw[i-1]*D%mod;
	}
}
ll has(string a){
	int l=a.length();
	ll res=0;
	rop(i,0,l){
		res=(res*D%mod)+((a[i]-'a'+1)%mod);
		res%=mod;
	}
	return res;
}
char s[N],_[N];
struct changee{
	int a,b,l;
}q[N];
int n,m;
ll pre[N];
ll cnt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=iread();
	m=iread();
	init(N-500);
	FOR(i,1,n){
		scanf("%s",s+1);
		scanf("%s",_+1);
		string c="";
		int l=strlen(s+1);
		q[i].l=l;
		FOR(i,1,l){
			c+=_[i];
		}
		q[i].b=has(c);
		c="";
		FOR(i,1,l){
			c+=s[i];
		}
		q[i].a=has(c);
//		cout<<c<<endl;
	}
	FOR(i,1,m){
		cnt=0;
		scanf("%s",s+1);
		scanf("%s",_+1);
		if(strlen(s+1)!=strlen(_+1)){
			puts("0");
			continue;
		}
		int l=strlen(s+1);
		string c="";
		FOR(i,1,l){
			c+=_[i];
		}
		ll ans=has(c);
		FOR(i,1,l){
			pre[i]=pre[i-1]*D%mod;
			pre[i]+=(s[i]-'a'+1)%mod;
			pre[i]%=mod;
		}
		FOR(i,1,l){
			FOR(j,1,n){
				int x=i+q[j].l-1;
				ll tmp=pre[x]-pre[i-1]*pw[q[j].l]%mod;
				tmp=(tmp+mod)%mod;
				if(tmp!=q[j].a) continue;
				tmp=tmp*pw[l-x]%mod;
				tmp=pre[l]-tmp;
				tmp=(tmp+mod)%mod;
				tmp=tmp+q[j].b*pw[l-x]%mod;
				tmp%=mod;
				if(tmp==ans) ++cnt;
			}
			if(s[i]!=_[i]) break;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}


