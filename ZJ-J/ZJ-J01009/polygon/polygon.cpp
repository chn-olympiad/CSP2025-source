#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],b[5001],cnt,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) cnt++;
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	if(cnt==n) cout<<((n-1)*(n-2)/2)%998244353;
	else if(n==3){
		cout<<(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))?1:0);
	}
	else{
		for(int i=3;i<=n;i++){
			for(int j=1,l=n;j<=i;j++,l--){
				ans*=l/j%998244353;
			}
		}
		cout<<ans;
	}
}
