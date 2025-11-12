#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647
#define mod 998244353
using namespace std;
ll n,m,ans=1;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void print(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
void write(ll x){print(x);putchar('\n');}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i)ans*=i,ans%=mod;
	write(ans);
	return 0;
}
