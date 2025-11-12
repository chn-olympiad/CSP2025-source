#include <bits/stdc++.h>
using namespace std;
int a[105],q,e,hang,lie;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
	int s = n*m;
	for (int i = 1; i <= s; i++){
		cin >> a[i];
	}
	q = a[1];
	sort(a+1,a+s+1); 
    for (int i = 1; i <= s; i++){
    	if (q == a[i])
    	e = s-i+1;
	}
	if (e <= n)
        cout << 1 << " " << e;
    else if (e%n==0){
    	lie = e/n;
    	if (e/n%2==0)
    	    hang = n-e%n+1;
    	else 
    	    hang = e%n;
    	cout << lie << " " << hang;
	}
	else if((e/n+1)%2==0){
        hang = n-e%n+1;
        lie = e/n+1;
        cout << lie << " " << hang;
    } 
    else{
        hang = e%n;
        lie = e/n+1;
        cout << lie << " " << hang;
    }
	return 0;
}
