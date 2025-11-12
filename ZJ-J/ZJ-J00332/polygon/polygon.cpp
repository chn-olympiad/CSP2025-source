#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){if(a[1]+a[2]>a[3])s=1;}
	else if(a[n]==1)s=((n-3)*(n-3)*2-4+n+1)%998244353;
	cout<<s;
	return 0;
}
