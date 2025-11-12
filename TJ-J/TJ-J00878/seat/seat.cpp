#include <bits/stdc++.h>
using namespace std;
long long n,m,a,ai,cnt=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	for(long long i = 1;i<n*m;i++){
		cin >> ai;
		if(ai > a) cnt++;
	}
	c = (cnt+n-1)/n;
	r = cnt%n;
	if(r == 0) r=n;
	if(c%2 == 1){
		cout << c <<" "<<r;
	}else{
		cout << c <<" "<<n-r+1;
	}
	return 0;
}
