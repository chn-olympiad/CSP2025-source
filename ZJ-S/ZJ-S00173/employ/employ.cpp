#include<bits/stdc++.h>
using namespace std;
long long a[505],sum[505],tmp[505];
long long n,i,j,k,m;
string s;
long long dp[505][505][2],pre[505][505][2];
long long val[1000005],invval[1000005];
const long long mod=998244353;
long long qpow(long long x,long long y){
	long long sum=1;
	while(y){
		if(y&1) sum*=x,sum%=mod;
		x*=x,x%=mod;
		y>>=1;
	}
	return sum;
}
long long inv(long long x){
	return qpow(x,mod-2);
}
long long C(long long x,long long y){
	return val[x]*invval[y]%mod*invval[x-y]%mod;
}
long long A(long long x,long long y){
	return val[x]*invval[x-y]%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	val[0]=1,invval[0]=1;
	for(i=1;i<=100000;i++){
		val[i]=val[i-1]*i%mod;
		invval[i]=inv(val[i]);
	}
	cin>>n>>m>>s;
	s=" "+s;
	for(i=1;i<=n;i++){
		cin>>a[i],sum[a[i]]++,tmp[a[i]]++;
	}
	  
	for(i=1;i<=500;i++)
	  sum[i]+=sum[i-1];
	sort(val+1,val+n+1);
	dp[0][n-sum[0]][1]=1;
	for(i=1;i<=n;i++){
		memcpy(pre,dp,sizeof(dp));
		memset(dp,0,sizeof(dp));
		for(j=0;j<=i;j++)
	      for(k=n;k>=0;k--){
	      	if(n-i-k<0) continue;
	        long long x=n-sum[j-1];
	        if(s[i]=='0'){
	      	    dp[j][k][0]+=pre[j-1][k+1][1],dp[j][k][0]%=mod;
		      	dp[j][k][0]+=pre[j-1][k][1]*(n-i-k+1)%mod,dp[j][k][0]%=mod;
		  	}
		 	 else{
			  	dp[j][k][0]+=pre[j-1][k][1]*(n-i-k+1)%mod;
			  	dp[j][k][1]+=pre[j][k+1][1]%mod;
			  	dp[j][k][0]%=mod;dp[j][k][1]%=mod;
			  }
	    }
	    for(j=0;j<=i;j++){
	    	for(k=n;k>=0;k--)
			  for(long long x=0;x<=tmp[j];x++)
			    if(k+tmp[j]-x<=n){
			      long long num=n-sum[j-1]-(k+tmp[j]-x);
			      if(num<0) continue;
				  dp[j][k][1]+=dp[j][k+tmp[j]-x][0]*C(tmp[j],x)%mod*A(num,x)%mod;
				  dp[j][k][1]%=mod;
			    }
		}
		/*
	  for(j=0;j<=n;j++){
	  	for(k=0;k<=n;k++){
	    	printf("%lld ",dp[j][k][0]);
		}
		printf("\n");
	  }
	  printf("\n");
	  for(j=0;j<=n;j++){
	  	for(k=0;k<=n;k++){
	    	printf("%lld ",dp[j][k][1]);
		}
		printf("\n");
		}
	  printf("\n");*/
	}
	long long ans=0;
	for(i=m;i<=n;i++){
		long long val=dp[n-i][0][1],sum1=0;
		for(j=n-i+1;j<=500;j++)
		  sum1+=tmp[j];
		for(j=n-i+1;j<=500;j++)
		  val*=A(sum1,tmp[j]),sum1-=tmp[j],val%=mod;
		ans+=val,ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}
