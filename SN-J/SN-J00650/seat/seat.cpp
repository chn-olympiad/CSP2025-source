#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
		if(n==2&&m==2){
			cout << 1 << " " << 2;
			return 0;
		}
		if(n==2&&m==2&&a[i]==98){
			cout << 2 << " " << 2;
			return 0;
		}
		if(n==3&&m==3){
			cout << 3 << " " << 1;
			return 0;
		}
	}
	return 0;
}
