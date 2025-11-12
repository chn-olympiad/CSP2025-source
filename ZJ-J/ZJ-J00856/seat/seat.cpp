#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long c,r;
long long a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long t=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	long long k=n*m;
	for (long long i=1;i<=n*m;i++){
		if (t == a[i]){
			k=i;
			break;
		}
	}
	long long x=k%n,y=k/n;
	if (x == 0){
		y--;
		x=n;
	} 
	c=y+1;
	if (y%2 == 1){
		r=n-x+1;
	}else{
		r=x;
	}
	cout<<c<<' '<<r;
	return 0;
}
