#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k,a[500001],s[1001][1001],dp[1002];
void A(){
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i+1]=dp[i]+1;
		for(int j=1;j<=i;j++){
			s[j][i]=s[j][i-1]^a[i];
			if(s[j][i]==k)dp[i+1]=min(dp[i+1],dp[j]+i-j);
		}
	}
	cout<<n-dp[n+1]<<endl;
}
void B(){
	int ones=0;
	for(int i=1;i<=n;i++){
		if(a[i])ones++;
	}
	if(k==1){
		cout<<ones<<endl;
		return;
	}
	if(ones<=1){
		cout<<n-ones<<endl;
		return;
	}
	int ans=0;
	bool flg=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			ans++;
			flg=0;
		}
		if(a[i]&&a[i+1]){
			if(!flg){
				ans++;
				flg=1;
			}
			else{
				flg=0;
			}
		}
	}
	cout<<ans<<endl;
}
void C(){
	return;
}
void D(){
	return;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n<=1000)A();
	else{
		bool flg1=1,flg2=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>=2){
				flg1=0;
			}
			if(a[i]>=256){
				flg2=0;
			}
		}
		if(flg1)B();
		else if(flg2)C();
		else D();
	}
	return 0;
}
//11.1 10:07
//code by K.S.
//want 65 pts.
