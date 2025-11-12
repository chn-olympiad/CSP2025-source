#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 505;
int n,m,ans,c[N],p[N],pre[N],r[N];
int jc[N],inv[N];
string s;
int ksm(int a, int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int C(int n,int m){
	return jc[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	jc[0]=inv[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=1ll*jc[i-1]*i%mod;
		inv[i]=ksm(jc[i],mod-2);
	}
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
	}
	if(n<=10){
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(i-1-cnt>=c[p[i]])continue;
				if(s[i]=='1')cnt++;
			}
			if(cnt>=m)ans++;
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",ans);
		return 0;
	}
	if(n<=18){
		for(int j=0;j<(1<<n);j++){
			if(__builtin_popcount(j)<m)continue;
			for(int i=0;i<=n;i++){
				pre[i]=0;
			}
			for(int i=1;i<=n;i++){
				if((j&(1<<i-1))==0)continue;
				pre[c[i]]++;
			}
			if(pre[0]!=0)continue;
			bool ok=1;
			for(int i=1;i<=n;i++){
				if(pre[i]>r[i]){
					ok=0;
					break;
				}
			}
			if(ok==0)continue;
			int res=1;
			for(int i=1;i<=n;i++){
				if(pre[i]+pre[i-1]>r[i]){
					res=0;
					break;
				}
				res=1ll*res*C(r[i]-pre[i-1],pre[i])%mod;
				pre[i]+=pre[i-1];
			}
			ans+=res;
		}
		printf("%d\n",ans);
	}
	return 0;
}

