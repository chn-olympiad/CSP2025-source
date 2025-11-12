#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,w[N],dp[N];
long long a[N],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	long long s=0;
	for(int i=n;i>=1;i--){
		s^=a[i];
		if(s==k){
			w[n]=i;
			break;
		}
	}
	for(int i=n-1;i>=1;i--){
		s^=a[i+1];
		if(a[i]==k){
			w[i]=i;
			s=a[i];
			continue;
		}
		int j=w[i+1]-1;
		if(w[i+1]==0) s=0,j=i;
		for(;j>=1;j--){
			s^=a[j];
			if(s==k){
				w[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(w[i]==0) dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[w[i]-1]+1);
	}
	cout<<dp[n];
	return 0;
}
