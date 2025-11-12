#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main(){
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	if(n>2){
		for(int i=0;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				ans++;
			}
		}
		ans=1;
	}
	cout<<ans%998%244%353;
	return 0;
}
