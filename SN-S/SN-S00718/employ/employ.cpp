#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e6+5;
int read () {
	int f=1,x=0;char ch=getchar();
	while (!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while (isdigit(ch)) {x=x*10+ch-48;ch=getchar();}
	return f*x;
}
int ans=0,a[N],f=1;
signed main () {
	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	int n=read(),k=read();
	string s;cin>>s;
	for(int i=1;i<=s.size();i++) {
		if(s[i-1]=='0') f=0;
	} 
	for(int i=1;i<=n;i++) 
		a[i]=read();
	if(f) {
		int sc=0;
		for (int i=1;i<=n;i++) {
			if(a[i]<=sc) sc++;
			else ans++;
		}
		if(ans<k) return cout<<0,0;
		else {
			int ans=1;
			for(int i=1;i<=n;i++) {
				ans*=i;
				if(ans>998244353)ans%=998244353;
			} cout<<ans;
		}
	}
	else cout<<0;
	return 0;
}
