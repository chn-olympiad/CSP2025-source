#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],ans,t;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
	}
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
//				if(a[i]==k)ans++;
				continue;
			}
			t=sum[j]^sum[i];
			if(t==k){
				ans++;
//				cout<<i<<' '<<j<<' '<<t<<"\n";
				i=j-1;
				break;
			}
		}
	}
	cout<<ans;
//	int d=sum[1]^sum[4];
//	cout<<d;
	return 0;
}
