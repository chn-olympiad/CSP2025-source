#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,k,a[maxn],tot,til;
struct ZS{
	int l,r;
}e[maxn],q[maxn];
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){e[++tot]=(ZS){i,j};break;}
		}
	}
	for(int i=1;i<=tot;i++){
		if(q[til].r<e[i].l) q[++til]=e[i]; 
		else if(q[til].r>e[i].r) q[til]=e[i];
	}
	printf("%d\n",til);
	return 0;
}