#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],sum1,cnt1,sum2,cnt2;
int main(){
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sum1=a[1];
	for(int i=2;i<=n;i++){
		if(sum1==k){
			cnt1++;
			sum1=a[i];
		}else{
			sum1^=a[i];
		}
	}
	if(sum1==k){
		cnt1++;
	}
	sum2=a[n];
	for(int i=n-1;i>=1;i--){
		if(sum2==k){
			cnt2++;
			sum2=a[i];
		}else{
			sum2^=a[i];
		}
	}
	if(sum2==k){
		cnt2++;
	}
	cout<<max(cnt1,cnt2);
	return 0;
}