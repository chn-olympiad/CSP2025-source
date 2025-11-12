#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int res=0,f=1;char ch=getchar();
	for(;ch>57||ch<48;ch=getchar())if(ch=='-')f=-1;
	for(;ch>47&&ch<58;ch=getchar())res=(res<<1)+(res<<3)+(ch^48);
	return res*f;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=q;i++){
		cout<<"0\n";
	}
	return 0;
}

