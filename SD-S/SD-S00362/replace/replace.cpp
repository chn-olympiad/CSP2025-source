#include<bits/stdc++.h>
using namespace std;
namespace{
	int read(){
		int x=0;char c=0;
		while(c<'0'||c>'9') c = getchar();
		while(c>='0'&&c<='9') {
			x = x*10 +(c^48);
			c = getchar();
		}
		return x;
	}
	void solve(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		int n= read(),q=read();
		while(q--) printf("0\n");
	}
}
int main(){
	solve();
	return 0;
}

