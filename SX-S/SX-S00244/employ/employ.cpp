#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,m,a[505];
char s[505];
int f[1<<18];
int p[1<<18];
int dp[1<<18][19];
bool cmp(int x,int y){
	return p[x]<p[y];
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++) f[i]+=((i>>j)&1);
		p[i]=i;
	}
	sort(p,p+(1<<n),cmp);
	dp[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++){
		for(int j=0;j<=f[i];j++){
			for(int k=0;k<n;k++){
				if((i>>k)&1) continue;
				int t=i+(1<<k);
				if(s[f[i]+1]=='1'&&a[k+1]>j) dp[t][j]=(dp[t][j]+dp[i][j])%P;
				else dp[t][j+1]=(dp[t][j+1]+dp[i][j])%P;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-m;i++) ans=(ans+dp[(1<<n)-1][i])%P;
	printf("%d\n",ans);
	return 0;
}
