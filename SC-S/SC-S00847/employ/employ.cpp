#include<bits/stdc++.h>
using namespace std;
using ll=long long;
//#define int ll
const int N=5e2+5,M=5e2+5,K=12,P=998244353;
template<typename T=int>inline T read(){
	T x=0;bool f=false;char c=getchar();
	while(c<'0'||c>'9') f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return f?-x:x;
}
int n,m,res,c[N];char s[N];
namespace SUB1_2{
	int res,sum,a[N];
	inline int main(){
		res=0;
		for(int i=1;i<=n;++i) a[i]=i;
		do{
			sum=0;
			for(int i=1,r=0;i<=n;++i){
				if(s[i]=='0'||r>=c[a[i]]) ++r;
				else ++sum;
			}
			res+=(sum>=m);
		}while(next_permutation(a+1,a+n+1));
		return res;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();scanf("%s",s+1);
	for(int i=1;i<=n;++i) c[i]=read();
	if(n<=10) res=SUB1_2::main();
	cout<<res;
	return 0;
}
/*
逆天ci=0诗人握持 
*/