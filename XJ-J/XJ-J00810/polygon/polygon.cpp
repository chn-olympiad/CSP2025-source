#include<bits/stdc++.h>
using namespace std;
long long int n,a[5050],sum[5050],qzd[5050],s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i],qzd[i]=max(qzd[i-1],a[i]);
	for(int k=3;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			if(sum[i+k-1]-sum[i-1]>2*qzd[i]) s++;
		}
	}
	cout<<s;
	return 0;
} 
