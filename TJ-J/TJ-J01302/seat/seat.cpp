#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105],b,e,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m);
    reverse(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			e=i+1;
			break;
		}
	}
	c=e/n+1;
	r=e%n;
	if(e%n==0){
		c--;
		r=n;
	}
	cout<<c<<' ';
	if(c%2) cout<<r;
	else cout<<(n-r)+1;
	return 0;
}
