#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int a[maxn],s[maxn],dp[maxn];
int sum[2000010];
int read(){
	int sum=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){sum=sum*10+(c-'0');c=getchar();}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		a[i]=read();
		s[i]=a[i]^s[i-1];
	}
	//k
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i-1;j>=0;j--){
			if(s[i]==k^s[j]){
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
			if(dp[j-1]<dp[i]) break;
		}
	}
	cout<<dp[n];

	return 0;
}