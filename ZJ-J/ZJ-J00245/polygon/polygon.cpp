#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
int a[N],sum;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++){
		for(int j=i+2;j<=n;j++){
			int ans=0;
			for(int k=i;k<=j;k++) ans+=a[k];
//			cout<<a[j]<<" "<<ans<<endl;
			if(ans>a[j]*2) sum++;
		}
	}
	cout<<(sum+sum/2)%998244353;
	return 0;
}