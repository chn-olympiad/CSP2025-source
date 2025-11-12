#include<bits/stdc++.h>
using namespace std;
int n,m,mx[500005],a[500005];
int s[500005],f=1;
int dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f=0;
		s[i]=s[i-1]^a[i];
	}
	if(f==1&&m<=1){
		int x=0;
		if(m==1){
			for(int i=1;i<=n;i++)
			  if(a[i]==1)
			    x++;
		}
		if(m==0){
			int y=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					x++;
					x+=y/2;
					y=0;
				}else
				 y++;
			}
		}
		cout<<x;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[j]=max(dp[j],mx[i-1]);
			if((s[j]^s[i-1])==m)
			  dp[j]=dp[i-1]+1;
			mx[j]=max(mx[j],dp[j]);
		}
	}
	cout<<dp[n];
	return 0;
}
