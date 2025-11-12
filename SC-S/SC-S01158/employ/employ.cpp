#include<bits/stdc++.h>
#define int long long
#define fast register int
using namespace std;
const int maxn=5e2+5,mod=998244353;

int n,m,ans,jc[maxn],add[maxn],k,c[maxn],sum,l;
string s;
bool flag;

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar('0'+x%10);
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(fast i=1;i<=n;i++){
		c[i]=read();
		if(c[i]==0){
			sum++;
			flag=true;
		}
	}
	jc[0]=1;
	for(fast i=1;i<=n;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	for(fast i=1;i<=n;i++){
		if(s[i-1]=='1'){
			l++;
		}
	}
	if(l-sum<m){
		cout<<0;
	}else if(m==n){
		for(fast i=1;i<=n;i++){
			if(s[i-1]=='0'){
				flag=true;
			}
		}
		if(flag==true){
			cout<<0;
		}else{
			cout<<jc[n];
		}
	}else if(m==1){
		for(fast i=1;i<=n;i++){
			if(s[i-1]=='1'){
				add[++k]=i;
			}
		}
		for(fast i=1;i<=k;i++){
			for(fast j=1;j<=n;j++){
				if(add[i]<=c[j]){
					ans=(ans+jc[n-1])%mod;
				}
			}
		}
		cout<<ans;
	}else{
		cout<<jc[n-sum];
	}
	return 0;
}