#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[100],m,n,k;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	k=a[0];
	sort(a,a+m*n);
	int i=0;
	for(;i<m*n;i++)if(a[i]==k)break;
	i=n*m-i-1;
	cout<<i/n+1<<' '<<((i/n%2)?n-i%n:i%n+1);
	return 0;
}
