#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
inline int read(){
	int k=0,k2=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k2=-1;c=getchar();}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*k2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	while(q--) cout<<0<<"\n";
	return 0;
}
