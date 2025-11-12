#include<iostream>
using namespace std;
int n,a[5010],sum,maxn,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(sum>2*maxn) ans++;
	cout<<ans%998244353;
	return 0;
}
