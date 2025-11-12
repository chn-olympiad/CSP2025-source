#include<bits/stdc++.h>
#define ll long long
#define debug printf("!!!\n")
using namespace std;
ll read(){
	char c=getchar();
	ll x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-') f=-1;
	}
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(ll x,char c){
	write(x);putchar(c);
}
const ll N=5e5+5;
ll n,k,a[N],s,ans;
map<ll,bool> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(ll i=1;i<=n;i++) a[i]=read();
	mp[0]=1;
	for(ll i=1;i<=n;i++){
		s^=a[i];
		if(mp[s^k]){
			ans++;mp.clear();
		}
		mp[s]=1;
	}
	write(ans,'\n');
	return 0;
}
/*
4 2
2 1 0 3
*/
