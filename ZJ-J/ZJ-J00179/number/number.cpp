#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define repp(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define getc getchar
#define putc putchar
#define scan scanf
#define prin printf
using namespace std;
const int N=1e6;
int p[10];
char s[N+100];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scan("%s",s);
	int n=strlen(s);
	rep(i,0,n-1)
		if('0'<=s[i]&&s[i]<='9')
			++p[int(s[i]-'0')];
	repp(i,9,0)
		rep(j,1,p[i])
			putc(i+'0');
	return 0;
}
