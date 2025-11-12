#include<bits/stdc++.h>
using namespace std;
int c = 0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int s = n*m;
	int a[s+5];
	for(int i = 1;i <= s;i++){
		cin >> a[i];
	}
	int b = a[1];
	sort(a+1,a+1+s);
	for(int i = 1;i <= s;i++){
		if(a[i] == b){
			c = s-i+1;
		}
	}
	if(c <= n){
		cout << 1 << " " << c;	
		return 0;
	}
	if(c % n == 0){
		cout << c/n << " " << n;	
	}else{
		if(m % 2 == 0){
			cout << c/n+1 << " " << n+1-c%n;	
		}else{
			cout << c/n+1 << " " << c%n;
		}
	}
 	return 0;
}
