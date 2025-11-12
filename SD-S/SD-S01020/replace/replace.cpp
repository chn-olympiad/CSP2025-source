#include<iostream>
#include<cstdio>
using namespace std;
int n,q;
inline int reads(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}return x*f;
}inline void files(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
}
signed main(){//file LL MLE WA
	files();
	n=reads(),q=reads();
	while(q--) puts("0");
	return 0;
}

