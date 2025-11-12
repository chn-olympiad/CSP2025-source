#include<bits/stdc++.h>
using namespace std;
long long mo=998244353;
long long n,m,k;
long long nai[4000];
long long mian[4000],ans=1;
long long yanghui[1000][1000];
long long zhi=1;
long long dp[1000][1000][3];
string st;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			if(i==0||i==j) yanghui[i][j]=1;
			else{
				yanghui[i][j]=yanghui[i-1][j]+yanghui[i-1][j-1];
				yanghui[i][j]%=mo;
			} 
		}
	}
	cin>>st;
	for(int i=1; i<=n; i++) {
		cin>>nai[i];
	}
	for(int i=0; i<n; i++) {
		mian[i+1]=int(st[i]-'0');
	}
	sort(nai+1,nai+1+n);
	while(nai[zhi]!=0){
		zhi++;
	}
	if(n-zhi<k) {
		cout<<0;
		return 0;
	}
	if(zhi==1){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mo;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}

