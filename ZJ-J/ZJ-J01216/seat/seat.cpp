#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long p = 1;
	long long my = 0;
	for(long long i = 1;i<=n*m;i++){
		long long t;
		cin >> t;
		if(i==1){
			my = t;
		}
		if(t>my){
			p++;
		}
	}
	
	long long ans1 = p/n;
	if(p%n!=0){
		ans1++;
	}
	long long ans2 = p-(ans1-1)*n;
	if(ans1%2==1){
		
	}else{
		ans2 = m-ans2;
	}
	cout << ans1 << " " << ans2;
	return 0;
}
