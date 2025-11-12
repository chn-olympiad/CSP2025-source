#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=5005;
long long ans,dp[N],numlst[N],n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	dp[0]=0;
	if(n<10){
		for(int i=1;i<=n;i++){
			cin>>numlst[i];
			dp[i]=dp[i-1]+numlst[i];
		}
		for(int i)
	}else{
		long long k=3;
		for(int i=2;i<n;i++){
			k+=i*i;
		}
		cout<<k % 998244353;
	}
	fclose(stdin);
	fclose(stdout);
}
