#include<bits/stdc++.h>
using namespace std;
#define ps putchar(' ')
#define pn putchar('\n')
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))
#define rec(x) scanf(" %c",&(x))

typedef long long ll;

template<typename T> void re( T &t){
	t=0;int f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	do{
		(t=((t<<3)+(t<<1)))+=(ch^48);
		ch=getchar();
	}while(ch>='0' && ch<='9');
	t*=f;
}

void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}

const int mod=998244353;

int n,m;
int nd[505];
int pl[505];
int nx[505];
int jc[505];
ll ans;

int main(){
	File("employ");
	re(n),re(m);
	for(int i=1;i<=n;i++){
		char c;
		rec(c);
		nd[i]=(c-'0');
	}
	int t=0;
	for(int i=1;i<=n;i++) re(nx[i]),t+=(!nx[i]);
	if(n>=100){
		if(n-t<m){
			wr(0);
			return 0;
		}
		jc[1]=ans=1;
		for(ll i=2;i<=n;i++){
			//wr(ans),pn;
			ans=(ans*i)%mod;
			jc[i]=ans;
		}
		ans=0;
		for(int i=1;i<=t;i++){
			int ct=0;
			for(int j=1;j<=n;j++) if(nx[i]) ct+=(nx[i]<=i);
			//wr(ans),pn;
			ans=(ans+jc[n-ct-t])%mod;
		}
		wr(ans);
	}
	else{
		for(int i=1;i<=n;i++) pl[i]=i;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(n-cnt<m) break;
				if(cnt>=nx[pl[i]]){
					++cnt;
					continue;
				}
				cnt+=(!nd[i]);
				//wr((nd[i])),pn;
			}
			if(n-cnt>=m) ans=(ans+1>=mod ? ans+-mod+1 : ans+1);
		}while(next_permutation(pl+1,pl+1+n));
		wr(ans);
	}
	
	return 0;
}
//Chtholly bless me!
//If happniess has a color,it must be the blue dyed by the last red!
//What are you doing in the end of the wolrd? Are you busy? Will you save us? 

