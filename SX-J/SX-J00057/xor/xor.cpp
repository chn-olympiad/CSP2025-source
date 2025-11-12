#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],sum,vis[5000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m){
			sum++;
			vis[i]=1;
		}
	}
	for(int i=1;i<n;i++){
		long long r=a[i];
		for(int j=i+1;j<=n;j++){
			if(vis[j]==1) break;
			if(a[j]==0) continue;
			r=r^a[j];
			if(r==m) sum++;
		}
	}
	cout<<sum;
	return 0;
}