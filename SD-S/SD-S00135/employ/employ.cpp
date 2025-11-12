#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<array>
#include<vector>
#include<string>
using namespace std;
const long long mod=998244353;
int n,m;
long long ans=0;
string s;
int c[501];
int p[501];
int dp[18][1<<18];
int calc(int x){
	int cnt=0;
	while(x){
		if(x&1)cnt++;
		x>>=1;
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
	}
	if(m>18&&m==n){
		if(s.find("0")){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
//	if(n<=10){
//		do{
//			int cnt=0;
//			for(int i=1;i<=n;i++){
//				if(cnt>=c[p[i]]||s[i]=='0'){
//					cnt++;
//				}
//			}
//	//		cout<<cnt<<'\n';
//			if(n-cnt>=m)ans++;
//			if(ans>mod)ans-=mod;
//		}while(next_permutation(p+1,p+n+1));
//		cout<<ans<<endl;
//		return 0;
//	}
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		int x=calc(i);
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				for(int k=0;k<=x-1;k++){
					if((x-1)-k>=c[j]||s[x]=='0')(dp[k][i]+=dp[k][i^(1<<(j-1))])%=mod;
					else (dp[k+1][i]+=dp[k][i^(1<<(j-1))])%=mod;
				}
			}
		}
	}
	for(int i=m;i<=n;i++){
		(ans+=dp[i][(1<<n)-1])%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
