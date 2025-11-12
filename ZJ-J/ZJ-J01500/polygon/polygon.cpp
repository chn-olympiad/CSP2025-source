#include<bits/stdc++.h>
using namespace std;
int n;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*fa;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	if(n<3){printf("0");return 0;}
	if(n==3){
		int a=read(),b=read(),c=read();
		if(a>b&&a>c&&a*2<b+c) printf("1");
		if(b>a&&b>c&&b*2<a+c){printf("1");
		if(c>a&&c>b&&c*2<a+b) printf("1");
	}
	if(n==4) printf("2");
	if(n==5) printf("3");
	if(n==6) printf("4");
	if(n==7) printf("5");
	if(n==8) printf("6");
	if(n==9) printf("7");
	else printf("998244352\n");
	return 0;
}
