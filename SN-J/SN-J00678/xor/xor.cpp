//SN-J00678 ¶ÎÑÅçÍ ¸¨ÂÖÖĞÑ§  
#include<bits/stdc++.h>
using namespace std;
int s[500001],n,k,a[500001],dp[500001];
map<int,bool>w;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int cnt=0;
	w[s[1]]=1;
	if(s[1]==k){
		dp[1]=1;
		cnt=1;
	}
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		int u=k^s[i];
		if(w[u]){
			dp[i]=dp[cnt]+1;
		}
		if(dp[i]!=dp[i-1]){
			for(int o=cnt;o<i;o++){
				w[s[o]]=0;
			}
			cnt=i;
		}
		w[s[i]]=1;
	}
	cout<<dp[n];
	return 0;
}
