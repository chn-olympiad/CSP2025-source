#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=1,k=0;char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) k=k*10+(c-'0'),c=getchar();
	return f*k;
}
const int mod=998244353,N=510;
int n,m,tot,ans,s[N],c[N],a[N],fac[N];
string st;
int qpow(int x,int p){
	int res=1;
	while(p){
		if(p&1) res=res*x%mod;
		x=x*x%mod;p>>=1;
	}
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();int flag=1;
	cin>>st;
	for(int i=0;i<st.size();i++) s[i+1]=st[i]-'0';
	for(int i=1;i<=n;i++) if(s[i]==0) flag=0;
	for(int i=1;i<=n;i++) c[i]=read();
	if(n<=18){
		tot=1;
		for(int i=1;i<=n;i++) a[i]=i,tot*=i;
		for(int i=1;i<=tot;i++){
			int renum=0,genum=0;
			for(int i=1;i<=n;i++){
				if(c[a[i]]<=renum){
					renum++;continue;
				}
				if(n-i+1+genum<m) break; 
				if(s[i]==0) renum++;
				else genum++;
				if(genum>=m) break;
			}
			if(genum>=m) ans++;
			next_permutation(a+1,a+1+n);
		} 
		cout<<ans;
	}else if(flag){
		fac[0]=1;int num=n;
		for(int i=1;i<=n;i++) if(c[i]==0) num--;
		if(num<m){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
		cout<<fac[num]*qpow(fac[num-m],mod-2)%mod*fac[n-m]%mod;
	}
	return 0;
}