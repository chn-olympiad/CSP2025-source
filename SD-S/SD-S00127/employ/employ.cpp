#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,mod=998244353;
ll dp[263005][20];
ll dp2[N];
int p[15];
int n,m;string s;
int a[N],sum[N],su[N];
bool cmp(int _,int __){
	return _>__;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=' '+s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=10){
		for(int i=n;i>=1;i--){
			a[i]=a[i-1];p[i]=i;
		}
		int ans=0;
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'||a[p[i]]<=i-1-cnt);
				else cnt++;
			}
			if(cnt>=m)ans++;
		}while(next_permutation(p+1,p+n+1));
		printf("%d\n",ans);
	}
	else if(n<=18){
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			int cnt=0;
			for(int j=0;j<n;j++){
				if(i&(1<<j))cnt++;
			}
			for(int j=0;j<n;j++){
				if(i&(1<<j));else continue;
				int x=i^(1<<j);
				for(int k=0;k<=n;k++){
					int p=cnt-k;
					if(a[j]>p&&s[cnt]=='1'&&k>0)dp[i][k]=(dp[i][k]+dp[x][k-1])%mod;
					else dp[i][k]=(dp[i][k]+dp[x][k])%mod;
				}
			}
		}
		printf("%lld\n",dp[(1<<n)-1][m]);
	}
	else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)sum[a[i]]++;
		for(int i=500;i>=1;i--){
			sum[i]=sum[i+1]+sum[i];
		}
		for(int i=1;i<=n;i++){
			su[i]=su[i-1];
			if(s[i]=='0')su[i]++;
		}
		dp2[n+1]=1;
		for(int i=n;i>=1;i--){
			dp2[i]=dp2[i+1]*(sum[su[i]+1]-(n-i))%mod;
		}
		printf("%lld\n",dp2[1]);
	}
	return 0;
}
