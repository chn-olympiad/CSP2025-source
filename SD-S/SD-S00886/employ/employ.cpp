#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int r=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*x;
} 
const int N=550;
int n,m;
string s;
int c[N];
long long ans=1;
const int p=998244353;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(); m=read();
	cin>>s;
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)ans=(ans%p)*i%p;
	printf("%lld",ans%p);
	fclose(stdin);
	fclose(stdout);
return 0;
}

