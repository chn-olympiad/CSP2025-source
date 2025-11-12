#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,s[511451],a[2114514],o,ans,lst=-1;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*f;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read();k=read();memset(a,0xcf,sizeof a);a[0]=-1;
	for(int i=1;i<=n;i++){
		o=read();s[i]=s[i-1]^o;
		if(a[s[i]^k]>=lst)lst=i,ans++;
		a[s[i]]=i;
	}
	cout<<ans;
	return 0;
}