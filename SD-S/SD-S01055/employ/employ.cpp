#include <bits/stdc++.h>
#define For(i,x,y) for(int (i)=(x);(i)<=(y);(i)++)
using namespace std;
typedef long long ll;
const int N=505,MOD=998244353;
ll read(){
	ll x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(ll x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
ll n,m,h[N],a[N],nw[N],ans,ful;
string sl;
bool vis[N];
set<int> s;
void dfs(int pos,set<int> snow){
	if(pos==n+1){
		int now=0;
		For(i,1,n){
			if(h[i]==0) now++;
			else if(now>=a[nw[i]]) now++;
		}
		if(now+m<=n) ans++;
		return;
	}
	set<int> sn;
	for(auto i:snow) sn.insert(i);
	for(auto i:snow){
		sn.erase(i);
		nw[pos]=i;
		dfs(pos+1,sn);
		sn.insert(i);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>sl;
	For(i,1,n){
		h[i]=sl[i-1]-'0';
		if(h[i]==0) ful=1;
	}
	For(i,1,n) a[i]=read();
	if(n<=10){
		For(i,1,n) s.insert(i);
		dfs(1,s);
		write(ans);
	}else{
		if(ful) write(0);
		else{
			ans=1;
			For(i,1,n) ans=ans*i%MOD;
			write(ans);
		}
	}
	return 0;
}
