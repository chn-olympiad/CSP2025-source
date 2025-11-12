#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],dis[5005][5005],sum[5005][5005],mx=0,ansz=0,anso=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
	}
	if(mx<=1){
		if(k>=2) cout<<0;
		else{
			for(long long i=1;i<=n;i++){
				if(a[i]==1) anso++;
				else ansz++;
			}
			if(k==1) cout<<anso;
			else cout<<ansz;
		}
		return 0;
	}
	for(long long i=1;i<=n;i++){
		dis[i][i]=a[i];
		sum[i][i]=(a[i]==k);
		for(long long j=i+1;j<=n;j++){
			dis[i][j]=(dis[i][j-1]^a[j]);
			sum[i][j]=(dis[i][j]==k);
		}
	}
	for(long long j=1;j<=n;j++){
		for(long long i=1;i<=j;i++) sum[i][j]=max(sum[i-1][j],sum[i][j]);
		for(long long i=j+1;i<=n;i++) sum[j+1][i]+=sum[j][j];
	}
	cout<<sum[n][n];
	return 0;
}
