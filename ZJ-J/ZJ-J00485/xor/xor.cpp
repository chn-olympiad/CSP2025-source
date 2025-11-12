#include<bits/stdc++.h>

using namespace std;

const int N=5e5+5;
const int M=1048590;

int n,k,b;

int a[N];
int s[N];

vector<int>c[M];

int dp[N];

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b=max(b,a[i]);
		s[i]=s[i-1]^a[i];
		c[s[i]].push_back(i);
	}
	if(k==1&&b<=1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		cout<<ans;
	}else if(k==0&&b<=1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i]^1;
			if(a[i-1]==1&&a[i]==1)ans++;
		}
		cout<<ans;
	}else if(b>255){
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			int idx=0;
			int x=s[i]^k;
			for(auto j:c[x]){
				if(j+1<=i)idx=j+1;
				else break;
			}
			if(idx!=0)dp[i]=max(dp[i],dp[idx-1]+1);
		}
		
		cout<<dp[n];
	}else{
		for(int i=1;i<=n;i++){
			int x=0;
			dp[i]=dp[i-1];
			for(int j=i;j>=1;j--){
				x^=a[j];
				if(x==k){
					dp[i]=max(dp[i],dp[j-1]+1);
					break;
				}
			}
		}
		
		cout<<dp[n];
	}
	
	return 0;
}

/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/