#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[5002];
long long cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=n-2;i>=1;i--){
		cnt=(cnt+i)%998244353;
	}
	cout<<cnt;
	return 0;
}
