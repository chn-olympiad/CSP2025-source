#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1],num;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++) if(a[i]==r) num=m*n-i+1;
	cout<<(num-1)/n+1<<' ';
	if(((num-1)/n+1)%2==1) cout<<(num-1)%n+1;
	else cout<<n-(num-1)%n;
	return 0;
}