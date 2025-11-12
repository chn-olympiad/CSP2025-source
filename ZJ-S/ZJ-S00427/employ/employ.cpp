#include<bits/stdc++.h>
using namespace std;
const int N=(1<<18)+5,P=998244353;long long n,m,a[505],b[505],dp[N][20],num[N],ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;char cc;for(int i=1;i<=n;i++) cin>>cc,b[i]=cc-'0';for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=18){
//		for(int i=1;i<=n;i++) cout<<i<<":"<<b[i]<<" "<<a[i]<<"\n";
		for(int i=1;i<(1<<n);i++) num[i]=num[i-(i&(-i))]+1;dp[0][0]=1;//cout<<num[(1<<5)-1]<<"!\n";
		for(int i=0;i<(1<<n);i++) for(int j=0;j<=n;j++) for(int k=1;k<=n;k++) if((i&(1<<(k-1)))==0) dp[i+(1<<(k-1))][j+(b[num[i]+1]&&a[k]>num[i]-j)]=(dp[i+(1<<(k-1))][j+(b[num[i]+1]&&a[k]>num[i]-j)]+dp[i][j])%P;
//		for(int i=0;i<(1<<n);i++) for(int j=1;j<=n;j++) cout<<i<<" "<<j<<":"<<dp[i][j]<<"\n";
		for(int i=m;i<=n;i++) ans=(ans+dp[(1<<n)-1][i])%P;cout<<ans;
	}
	return 0;
}
