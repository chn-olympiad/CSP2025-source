#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define lowbit(x) x&-x
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const int N=505,mod=998244353;
ll T=1,n,m,c[N],inv[N],ans;
string s;
bitset<N>vis;
inline void dfs(ll x,ll y){
	if(y>=m){
		ans+=inv[n-x+1];
		if(ans>=mod) ans-=mod;
		return;
	}
	if((x>n)||(y+n-x+1<m)){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(x+1,y+(s[x]=='1'&&c[i]>(x-y-1)));
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	T=read();
	while(T--){
		n=read();
		m=read();
		cin>>s;
		s=" "+s;
		inv[0]=1;
		bool f=true;
		ll res=0,num=n;
		for(ll i=1;i<=n;i++){
			c[i]=read();
			inv[i]=inv[i-1]*i%mod;
			if(c[i]==0) num--;
			if(s[i]=='0') f=false;
		}
		if(m==n&&num!=n){
			puts("0");
			return 0;
		}
		if(f&&num==n){
			write(inv[num]);
			putchar('\n');
			return 0;
		}
		dfs(1,0);
		write(ans);
		putchar('\n');
		return 0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'){
				res++;
			}else{
				f=false;
				break;
			}
		}
	}
	return 0;
}
