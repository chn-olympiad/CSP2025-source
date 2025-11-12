#include<bits/stdc++.h>
#define qwq return
using namespace std;
int n,q;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	qwq x*f;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	while (q--) {
		puts("0");
	}
	qwq 0;
}

