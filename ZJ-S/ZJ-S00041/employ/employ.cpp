#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int sum=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const int N=505;
const int mod=998244353;
int n,m,ans,x;
char s[N];
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) cin>>s[i];
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++){
		if(c[i]) x++;
	}
	ans=1;
	for(int i=1;i<=x;i++){
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
