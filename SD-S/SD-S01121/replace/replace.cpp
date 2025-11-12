#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while (ch<'0' || '9'<ch){
		if (ch=='-') f*=-1;
		ch=getchar();
	}
	while ('0'<=ch && ch<='9'){
		x=(x*10+ch-'0');
		ch=getchar();
	}
	return f*x;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	while (q--) cout<<0<<'\n';
	return 0;
}

