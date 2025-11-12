#include<bits/stdc++.h>
using namespace std;
int dp[500010],dx[500010],a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdin);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		int j=i,t=-1;
		while(j<=n&&t==-1){
			int q=dp[j]^dp[i-1];
			if(q==k) t=j;
			j++;
		}
		dx[i]=t;
	}
    int p=0,ans=0;
	for(int i=1;i<=n;i++){
		if(i>p&&dx[i]!=-1){
			ans++;
			p=dx[i];
		}
		else if(dx[i]<p&&dx[i]!=-1) p=dx[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}