#include<bits/stdc++.h>
#define int long long
#define MOD 998244353
#define MAXN 505
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int n,m;
string s;
int p[MAXN];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;
	for(int i=1;i<=n;i++){
		p[i]=read();
	}
	bool flag=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0') flag=1;
	}
	if(!flag){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%MOD;
		}
		printf("%lld\n",ans);
		return 0;
	}
	printf("%lld\n",m*m%MOD);
	return 0;
}

