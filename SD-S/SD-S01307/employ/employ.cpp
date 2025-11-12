#include<bits/stdc++.h>
#define qwq return
using namespace std;
const int N=505,P=998244353;
int n,m,ans;
char s[N];
int c[N],p[N];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	qwq x*f;
}
void sub1() {
	for (int i=1;i<=n;i++) {p[i]=i;}
	do {
		bool f=1;
		for (int i=1,j=0;i<=n;i++) {
			if (s[i]=='0' || j>=c[p[i]]) {j++;}
			if (n-j<m) {f=0;break;}
			if (i-j>=m) {break;}
		}
		ans+=f;
	}while (next_permutation(p+1,p+n+1));
	printf("%d\n",ans>P?ans-P:ans);
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) {c[i]=read();}
	sub1();
	qwq 0;
}
/*
3 2
101
1 1 2
[2]

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
[2204128]
*/
