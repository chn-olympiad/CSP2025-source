#include <bits/stdc++.h>
using namespace std;

long long a[120];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	long long n,m,temp;
	cin >> n >> m;
	for(long long i = 1; i <= (n * m); i ++){
		cin >> a[i];
	}
	temp = a[1];
	bool hui = false;
	sort(a, a + (n * m) + 1);
	reverse(a + 1, a + (n * m) + 1);
	long long hang = 1, lie = 1;
	for(long long i = 1; i <= (n * m); i++){
		if(a[i] == temp){
			cout << lie << ' ' << hang;
			return 0;
		}
		if(!hui){
			hang ++;
		}else{
			hang --;
		}
		if((!hui && hang > n) || (hui && hang < 1)){
			lie ++;
			if(!hui){
				hang --;
			}else{
				hang ++;
			}
			hui = !hui;
		} 
	}
	return 0;
}
