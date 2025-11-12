#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],pre[500005],d,ans,dq,q,dp[500005];
long long yh(long long x,long long y){
	return (x|y)-(x&y);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=yh(pre[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		d=0;
		q=0;
		for(int j=i;j<=n;j++){
			for(int o=q;o<j;o++){
				if(yh(pre[o],pre[j])==k){
					q=o+1;
					d++;
					//cout<<j<<" ";
					break;
				}
			}
		}
		//cout<<endl;
		ans=max(ans,d);
	}
	cout<<ans;
	return 0;
}
