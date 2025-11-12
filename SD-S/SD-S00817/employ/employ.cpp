#include <bits/stdc++.h>
#define int long long
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define F(i,a,b,c) for(int i=a;i>=b;i-=c)
using namespace std;
const int N=1e5+1;
const int mod=998244353;
int n,m,a[N],c[N],ans;
string s;
int read(){
	int X=0,F=1;
	char C=getchar();
	while(C<'0'||C>'9'){if(C=='-') F=-1;C=getchar();}
	while(C>='0'&&C<='9'){X=X*10+C-'0';C=getchar();}
	return X*F;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	f(i,1,n,1){a[i]=s[i-1]-'0';if(a[i]==0) a[0]=1;}
	f(i,1,n,1){c[i]=read();if(c[i]==0) c[0]++;}
	if(n<(m+c[0])||(n==m&&a[0]==1)) puts("0");
	else{
		ans=1;
		f(i,1,n,1) ans=ans*i%mod;
		printf("%lld",ans);
	}
	return 0;
}
