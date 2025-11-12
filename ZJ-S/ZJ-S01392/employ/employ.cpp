#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
int n,m,i,a[600],ss,f[600],g[600],f1,x;
char s[600];
int sc(int t,int w){
	if(w>=m)return f[t];
	if(t>n)return 0;
	int sss=0;
	for(int i=1;i<=n;i++)
		if(!g[i]){
			g[i]=1;int k=w;
			if(s[t]=='0');
			else if(t-w-1>=a[i]);
			else k++;
			sss=(sss+sc(t+1,k))%mod;
			g[i]=0;
		}
	return sss;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	f1=1;
	for(i=1;i<=n;i++)
		if(s[i]=='0'||!a[i]){
			f1=0;break;
		}
	if(f1==1){
		ss=1;
		for(i=1;i<=n;i++)ss=ss*i%mod;
		printf("%lld",ss);
		return 0;
	}
//	for(i=n-1;i>=0;i--){
// 		if(s[i]=='0')x++;
//		else if(x>=a[i+1])x++;
//	}
//	if(n-x<m){
//		printf("0");return 0;
//	}
	f[n+1]=1;
	for(i=n;i>=1;i--)f[i]=f[i+1]*(n-i+1)%mod;
	printf("%lld",sc(1,0));
	return 0;
}
