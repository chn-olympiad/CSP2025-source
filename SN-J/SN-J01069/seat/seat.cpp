#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1023;
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
bool cmp (int a,int b) {
	return a>b;
}
int n,m,a[N],r,tmp,x=1,y=1;
signed main () {
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) {
		if(i==1)a[1]=r=read();
		else a[i]=read();
	} 
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)  
		if(a[i]==r) tmp=i;
	while (--tmp) {
		if(y%2==1) {
			if(x<n) x++;
			else y++;
		} else {
			if(x>1) x--;
			else y++;
		}
	} write(y);
	putchar(' ');
	write(x);
	return 0;
}
