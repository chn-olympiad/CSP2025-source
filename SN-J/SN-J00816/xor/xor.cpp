#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

int n,k;
int a[N],s[N];
int dp[N],mx[(1<<21)+5];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=0;i<(1<<21);i++)mx[i]=INT_MIN;
	mx[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(mx[k^s[i]]+1,dp[i-1]);
		mx[s[i]]=max(mx[s[i]],dp[i]);
	}
	cout<<dp[n];
	return 0;
}
