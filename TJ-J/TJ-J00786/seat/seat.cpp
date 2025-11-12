#include <bits/stdc++.h> 
using namespace std;

int s[150];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> s[1];
	int t = s[1];
	for(int i = 2; i <= n * m; i++)
		cin >> s[i];
	sort(s + 1, s + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++){
		if(s[i] == t){
			int lie = int(ceil((double)i / n));
			int hang;
		    if(lie % 2) hang = (i - 1) % n + 1;
		    else hang = n - (i - 1) % n;
			cout << lie << " " << hang;
			return 0; 
		}
	}
	return 0;
}
