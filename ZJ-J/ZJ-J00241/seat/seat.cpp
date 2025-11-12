#include<bits/stdc++.h>
using namespace std;
long long n,m,a[150];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	long long i,x=1;
	for(i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) x++;
	}
	cout<<(x-1)/n+1<<" ";
	if((x-1)/n%2==0) cout<<x%n+(x%n==0)*n;
	else cout<<n-x%n-(x%n==0)*n+1;
	return 0;
}