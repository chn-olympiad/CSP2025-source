#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,k;
int a[N],dp[N],l[N];
map<int,int> mp;
int cur;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	cur=0;
	for(int i=1;i<=n;i++){
		cur^=a[i];
		mp[a[i]^cur]=i;
		int ret=(k^cur);
		if(mp[ret]!=0){
			l[i]=mp[ret];
		}
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(l[i]==0)dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[l[i]-1]+1);
	}
	cout<<dp[n];
	return 0;
}