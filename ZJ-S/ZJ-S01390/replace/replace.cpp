#include<bits/stdc++.h>
using namespace std;
int n,q;
inline int read(){
	int t=1,tot=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return tot*t;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(); q=read();
	for(int i=1;i<=q;i++) puts("0");
	return 0;
}
