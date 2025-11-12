#include<bits/stdc++.h>//能力到极限了,100+100+25+24=249,18:09 
using namespace std;
const long long mod=998244353;
int n,m,a[505],f[19][1<<18],s[505],b[505],dp[505][505];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='0'&&ch!='1')ch=getchar();
	    s[i]=ch=='0'?0:1;
}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n==m){
		for(int i=1;i<=n;i++){
			if(!s[i]){
				printf("0\n");
				return 0;
			}
		};
		for(int i=1;i<=n;i++)
		if(a[i]==0){
			printf("0\n");
			return 0;
		}
		long long x=1;
		for(int i=1;i<=n;i++)x=x*i%mod;
		printf("%lld\n",x);
		return 0;
	}
	if(n<=18){
	f[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++){
		int cnt=1;
		for(int j=0;j<n;j++)if((i>>j)&1)cnt++;
		for(int j=0;j<n;j++){
			if((i>>j)&1)continue;
			for(int k=0;k<n;k++){
				if(s[cnt]==0||cnt-k-1>=a[j+1]){
					(f[k][i|(1<<j)]+=f[k][i])%=mod;
				}else
				(f[k+1][i|(1<<j)]+=f[k][i])%=mod;
			};
		}
	}
	for(int i=m;i<=n;i++)(ans+=f[i][(1<<n)-1])%=mod;
	printf("%lld\n",ans);
	return 0;
}
    printf("0\n");
//    if(m==1){
//    	for(int i=1;i<=n;i++)if(s[i]==0)b[++b[0]]=i;
//    	sort(a+1,a+1+n);
//    	for(int i=1;i<=b[0];i++)
//		for(int j=1;j<=n;j++){
//    		if(a[j]<b[i]){
//    			for(int k=1;k<=n;k++)
//    			(f[i][j]+=f[i-1][k]);
//			};
//		}
//	}
	return 0;
}
