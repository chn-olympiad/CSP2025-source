#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],z,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) z++;
	}
	ans=z/n+1;
	cout<<ans<<' ';
	if(ans%2) cout<<z%n+1;
	else cout<<n-z%n;
	return 0;
}

