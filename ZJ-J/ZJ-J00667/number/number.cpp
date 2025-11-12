#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#define rep(i,s,e) for(int i=(s);i<=(e);++i)
#define _rep(i,s,e) for(int i=(s);i<(e);++i)
#define rev(i,s,e) for(int i=(s);i>=(e);--i)


const int N=1e6+10;

int n,l,t[10];
char a[N];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::cin>>a;
	l=strlen(a);
	_rep(i,0,l) if(isdigit(a[i])) t[a[i]-'0']++;
	rev(i,9,0) while(t[i]--) putchar('0'+i);
	return 0;
}
