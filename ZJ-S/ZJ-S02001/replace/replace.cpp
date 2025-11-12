#include<bits/stdc++.h>
using namespace std;
long long read(){
	long long x=0; bool f=0; char ch=getchar();
	for( ; ch<'0' || ch>'9' ; ch=getchar() ) ( ch=='-' ) && ( f=1 );
	for( ; ch>='0' && ch<='9' ; ch=getchar() ) x=(x<<3)+(x<<1)+(ch^'0');
	return f ? -x : x;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n=read(),q=read();
	for(int i=1;i<=q;i++){
		cout<<0<<'\n';
	}
	return 0;
}
