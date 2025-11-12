#include<bits/stdc++.h>
using namespace std;
int a[1000008];
int main(){
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m , s , Rpoint , Rrank , x , y;
	x = y = 0;
	cin >> n >> m;
	s = n * m;
	for(int i = 1; i <= s; i ++){
		cin >> a[i];
	}
	Rpoint = a[1];
	sort(a + 1 , a + s + 1);
	for(int i = 1; i <= s; i ++){
		if(a[i] == Rpoint){
			Rrank = s - i + 1;
			break;
		}
	}
	while(Rrank > 0){
		if(Rrank <= 2 * m){
			if(Rrank <= m){
				x ++;
				y = Rrank;
			} else{
				x += 2;
				y = 2 * m - Rrank + 1;
			}
			Rrank -= 2 * m;
			break;
		} else{
			x += 2;
			Rrank -= 2 * m;
		}
	}
	cout << x << " " << y;
	return 0;
}
