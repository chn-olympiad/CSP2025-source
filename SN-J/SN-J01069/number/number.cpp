#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 123;
int read () {
	int f=1,x=0;char ch=getchar ();
	while (!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while (isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
void write (int x) {
	if(x<0) {putchar('-');x=-x;}
	if(x>=10) write(x/10);
	putchar(x%10+48);
}
int tp[N];
char ch;
signed main () {
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	while (cin>>ch) {
		if(isdigit(ch)) 
			tp[ch-48]++;
	} for(int i=9;i>=0;i--) {
		while (tp[i]!=0) {
			tp[i]--;cout<<i;
		}
	} 
	return 0;
}
