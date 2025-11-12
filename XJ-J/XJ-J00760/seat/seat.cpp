#include<bits/stdc++.h>
using namespace std;

int a, b, c[200], d[200], e, f, g;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> a >> b;
	for (int i = 1; i <= a * b; i++){
		cin >> c[i];
		d[i] = i;
	}
	for (int i = 1; i <= a * b - 1; i++){
		for (int j = i + 1; j <= a * b; j++){
			if (c[i] < c[j]){
				e = c[i];
				c[i] = c[j];
				c[j] = e;
				e = d[i];
				d[i] = d[j];
				d[j] = e;
			}
		}
	}
	for (int i = 1; i <= a * b; i++){
		if (d[i] == 1){
			f = i / a;
			g = i % a;
			if (g == 0){
				if (f % 2 != 0){
					cout << f << " " << a;
				}
				else{
					cout << f << " " << 1;
				}
				break;
			}
			if ((f + 1) % 2 != 0){
				cout << f + 1 << " " << g;
			}
			else{
				cout << f + 1 << " " << a - g + 1;
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
