#include <bits/stdc++.h>
using namespace std;
int main() {

	freopen("emply.in", "r", stdin);
	freopen("emply.out", "w", stdout);
	int n,m;
	cin>>n>>m;
	char s[100000];
	for(int i=1;i<=n;i++)cin>>s[i];
	
	int a[100000];
	for(int i=1;i<=n;i++)cin>>n;
	long long ans=0,sum=1;
	for(int i=m;i<=n;i++){
		for(long long j=n;j>n-i;j--){
			sum*=j;
		}
		ans+=sum;
	} 
	cout<<ans;
	return 0;
}
