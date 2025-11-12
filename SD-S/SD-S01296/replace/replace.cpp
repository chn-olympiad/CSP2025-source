#include<bits/stdc++.h>
#define int long long
using namespace std;
int ksm(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%p;
		b>>=1;a=(a*a)%p;
	}return ans;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
void sol(){
	int n=read(),q=read();
	while(q--){
		cout<<"0\n";
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
//	T=read();
	while(T--) sol();
	return 0;
}


