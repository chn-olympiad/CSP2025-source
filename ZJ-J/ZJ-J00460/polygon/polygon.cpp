#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			int sum=0,maxx=-1;
			for(int k=i;k<=j;k++){
				sum+=a[k];
				maxx=max(maxx,a[k]);
				if(sum>maxx*2)ans++;
			}
		}
	cout<<ans%998244353;
	return 0;
}
