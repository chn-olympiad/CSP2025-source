#include <bits/stdc++.h>
using namespace std;
const int maxn=5005;
int n,m,tot,a[maxn],x,s;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
int find(){
	int l=1,r=tot;
	while(l<=r){
		int mid=(r-l>>1)+l;
		if(a[mid]==x) return mid;
		if(a[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();tot=n*m;
	for(int i=1;i<=tot;i++) a[i]=read();
	x=a[1];sort(a+1,a+tot+1);
	s=find();s=tot-s+1;
	int A=(s-1)/n+1,B=(s-1)%n+1;
	if(A&1) printf("%d %d\n",A,B);
	else printf("%d %d\n",A,n-B+1);
	return 0;
}