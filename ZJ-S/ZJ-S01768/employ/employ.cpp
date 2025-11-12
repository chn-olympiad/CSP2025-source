#include<bits/stdc++.h>
#define int long long
#define p 998244353
using namespace std;
int n,m;
string s;
int a[509],pai[509];
int dp[1000009][22];
inline void solve1(){
	int fl=1;
	for(int i=1;i<=n;i++) if(s[i]=='0'||a[i]==0) fl=0;
	if(fl==1) cout<<pai[n]<<'\n';
	else cout<<0<<'\n';
}
inline int coun(int x){
	int sum=0;
	while(x) {
		if(x%2==1) sum++;x/=2;
	}return sum;
}
inline void solve2(){
	dp[0][0]=1;
	for(int i=0;i<=(1<<n)-1;i++){
		int v=coun(i);
		for(int j=1;j<=n;j++){
			if((i|(1<<(j-1)))==i) continue;
			for(int k=0;k<=n;k++){
				if(s[v+1]=='0') dp[i+(1<<(j-1))][k]+=dp[i][k];
				else{
					if(a[j]<=v-k) dp[i+(1<<(j-1))][k]+=dp[i][k];
					else dp[i+(1<<(j-1))][k+1]+=dp[i][k];
				}
			}
		}
	}int ans=0;
	for(int i=m;i<=n;i++) ans+=dp[(1<<(n))-1][i];
	cout<<ans%p<<'\n';
}
inline void solve3(){
	int sum=0;
	
	//for(int )
}
int qian[1009];
inline void solve4(){
	int ans=pai[n];
	int sum=1;
	for(int i=1;i<=n;i++) qian[a[i]]++;
	for(int i=1;i<=n+1;i++) qian[i]+=qian[i-1];
	int num=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			
			sum*=max(0ll,qian[i-1]-num);sum%=p;num++;
		}
	}
	cout<<(ans-sum*pai[n-num]+p)%p<<'\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	pai[0]=1;
	for(int i=1;i<=500;i++) pai[i]=pai[i-1]*i%p;
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	//solve4();return 0;
	if(n==m) solve1();
	else if(n<=18) solve2();
	else if(m==1) solve4();
	else{
		int fl=1;
		for(int i=1;i<=n;i++){
			if(s[i]=='0') fl=0; 
		}
		if(fl==1) solve3();
	}
	
	return 0;
}
