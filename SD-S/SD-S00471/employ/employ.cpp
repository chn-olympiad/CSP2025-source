#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int n,m;
char s[505];
int c[505];
void solve1(){
	for(int i=1;i<=n;i++)
		if(s[i]=='0'||!c[i]){
			printf("0");
			return;
		}
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*i%mod;
	printf("%lld\n",ans);
	return;
}
int p[11]; 
void solve2(){
	for(int i=1;i<=n;i++)
		p[i]=i;
	int ans=0;
	do{
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&c[p[i]]>cnt1) cnt2++;
			else cnt1++;
		}
		if(cnt2>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return;
}
int dp[1<<18][20];
void solve3(){
	for(int i=0;i<n;i++){
		s[i]=s[i+1];
		c[i]=c[i+1];
	}
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j)) cnt++;
		for(int j=0;j<=n;j++){
			if(!dp[i][j]) continue;
			for(int k=0;k<n;k++){
				if(i&(1<<k)) continue;
				int id=i|(1<<k);
				if(c[k]>cnt-j&&s[cnt]=='1') dp[id][j+1]=(dp[i][j]+dp[id][j+1])%mod;
				else dp[id][j]=(dp[i][j]+dp[id][j])%mod;
			}
		}
	}
	long long ans=0;
	for(int i=m;i<=n;i++)
		ans=(ans+dp[(1<<n)-1][i])%mod;
	printf("%lld\n",ans);
	return;
}
int t[505];
void solve4(){
	for(int i=1;i<=n;i++)
		t[c[i]]++;
	long long sum=0,ans=1,cnt=0,fac=1;
	for(int i=1;i<=n;i++){
		fac*=i%=mod;
		sum+=t[i-1];
		if(s[i]=='1'){
			ans*=sum%=mod;
			sum--;
		}
		else{
			cnt++;
			ans*=cnt%=mod;
		}
	}
	printf("%lld",fac-ans);
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		sum+=c[i];
	}
	if(n==m){
		solve1();
		return 0;
	}
	if(n<=10){
		solve2();
		return 0;
	}
	if(n<=18){
		solve3();
		return 0;
	}
	if(m==1){
		solve4();
		return 0;
	}
	return 0;
}
