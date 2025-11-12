#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=1e6+10;
ll n,m,k,c[N],ans=1,inf=998244353;
string s;
ll read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	s=read();
	for(ll i=1;i<=n;i++){
		c[i]=read();
	}
	for(ll i=1;i<=n;i++){
		ans=ans*i%inf;
	}
	cout<<ans<<"\n";
	return 0;
}
