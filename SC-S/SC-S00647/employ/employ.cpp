#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const ll mod=998244353;
int n,m,c[N],s[N],flag=1,dp[N];
ll ans=1;
string ss;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>ss;
	for(int i=0;i<ss.size();i++){
		s[i+1]=(ss[i]-'0');
		if(s[i+1]!=1)	flag=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	if(flag){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(dp[i-1]>=c[i]){
				dp[i]=dp[i-1]+1;
			}	
			else{
				dp[i]=dp[i-1];
				cnt++;
			} 
		}
		if(cnt<m){
			printf("0");
			return 0;
		}
		for(int i=1;i<=n-m;i++){
			ans*=i;
			ans%=mod;
		}
		for(int i=cnt-m+1;i<=cnt;i++){
			ans*=i;
			ans%=mod;
		}
		printf("%lld",ans);
		return 0;
	} 
	printf("0");
	return 0;
}