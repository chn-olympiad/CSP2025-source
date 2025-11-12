#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],sum;
long long mk[N*N],cnt;
unordered_map<int,unordered_map<int,long long> >dp;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	mk[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=0;j--){
			dp[j+a[i]][i]=(dp[j+a[i]][i]+mk[j])%mod;
			mk[j+a[i]]=(mk[j+a[i]]+mk[j])%mod;
			if(j>a[i]) cnt=(cnt+dp[j+a[i]][i])%mod;
		}
		sum+=a[i];
	}
	cout<<cnt;
	return 0;
}
