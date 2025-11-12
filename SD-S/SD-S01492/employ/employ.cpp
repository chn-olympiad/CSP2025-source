#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const int MOD=998244353;
int c[505],fac[505],p[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int N=500;
	fac[0]=1;
	for(int i=1;i<=N;i++) fac[i]=fac[i-1]*i%MOD;
	int n=read(),m=read();
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) c[i]=read();
	int f=0;
	for(int i=1;i<=n;i++){
		if(!c[i]||s[i-1]=='0'){
			f=1;
			break;
		}
	}
	if(!f){
		cout<<fac[n]<<'\n';
		return 0;
	}
	if(n==m){
		cout<<0<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	while(true){
		int goo=0,wor=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') wor++;
			else{
				if(wor>=c[p[i]]) wor++;
				else goo++;
			}
		}
		if(goo>=m){
			ans++;
			ans%=MOD;
		}
		next_permutation(p+1,p+n+1);
		int f=0;
		for(int i=1;i<=n;i++){
			if(p[i]!=i){
				f=1;
				break;
			}
		}
		if(!f) break;
	}
	cout<<ans<<'\n';
	return 0;
}
