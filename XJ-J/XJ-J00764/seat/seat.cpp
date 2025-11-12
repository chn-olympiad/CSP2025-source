#include<bits/stdc++.h>
using namespace std;
long long int n,m,b[110],len,a11,di=0,lie=0,hang=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	len = n*m;
	for(int i=1;i<=len;i++){
		cin >> b[i];
	}
	a11 = b[1];
	sort(b+1,b+1+len);
	for(int i=len;i>=1;i--){
		if(b[i]==a11){
			di = len-i+1;
		}
	}
	if(di%n==0){
		lie = di/n;
		if(lie%2==0){
			cout << lie << ' ' << 1;
		}else{
			cout << lie << ' ' << n;
		}
	}else {
		lie = di/n+1;
		if(lie%2==0){
			cout << lie << ' ' << n-(di%n)+1;
		}else cout << lie << ' ' << di%n;
	}
	return 0;
} 

