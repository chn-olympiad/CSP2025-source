#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k=1,l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])k++;
	}
	if(!k%n)h=n;
	else h=k%n;
	l=k/n;
	if((double)k/n!=k/n)l++;
	cout<<l<<' ';
	if(l%2)cout<<h;
	else cout<<n-h+1;
	return 0;
}
