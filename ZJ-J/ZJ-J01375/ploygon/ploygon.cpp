#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,MOD=998244353;
inline int rd(){
	int f=1;char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-f;
	int x=(c&15);while(isdigit(c=getchar()))x=(x<<3)+(x<<1)+(c&15);
	return x*f;
};
int a[N],sum[N],dp[510][N],ans=0;
int main(){
	freopen("ploygon.in","r",stdin);
	freopen("ploygon.out","w",stdout);
	int n=rd(),tot=0;;
	for(int i=1;i<=n;i++)a[i]=rd(),tot+=a[i];
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int j=0;j<=tot;j++){
		for(int i=1;i<=n;i++){
			if(a[i]>j)continue;
			dp[i][j]+=dp[i-1][j-a[i]];
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=a[i]+1;j<=tot;j++) {
			ans+=dp[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
