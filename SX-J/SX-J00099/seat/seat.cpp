#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,jilu,ll,lh;
	int a[110];
	cin >> n >> m;
	int num;
	for(int i=0; i<n*m; i++){
		cin >> a[i];
	}
	jilu=a[1];
	sort(a,a+n*m);
	for(int i=0; i<n*m; i++){
		if(a[i]==jilu){
			num=n-i+1;
		}
	}
	if(num%n!=0){
		ll=num/n+1;
	}else{
		ll=num/n+1;
	}
	if(ll%n != 0){
		if(num%n==0){
			lh=n+1;
		}else{
			lh=num%n+1;
		}
	}else{
		int k;
		k=num%n;
		lh=n-k+1;
	}
	cout << ll  << " " << lh;
	return 0;
}