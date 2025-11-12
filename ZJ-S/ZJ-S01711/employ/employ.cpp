#include<bits/stdc++.h>
using namespace std;
const int N=505;
typedef long long ll;
const ll mod=998244353;
int n,m,c[N];
string s;
ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
bool caseA(string s) {
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='0') return false;
	}
	return true;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	int x=n;
	for(int i=1; i<=n; i++) {
		c[i]=read();
		if(c[i]==0) x--;
	}
	if(caseA(s)) {
		ll res=1;
		for(ll i=1;i<=x;i++){
			res=(res*i)%mod;
		}
		printf("%lld\n",res);
	}
	return 0;
}