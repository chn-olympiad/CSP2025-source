#include <iostream>
using namespace std;

int main() {
	#freopen("road.in","r")studin;
	#freopen("road.out',"w")studin;
	int n, m, k, v = 0, nmk;
	cin >> nmk;
	for (int i; nmk; 0) {
		if (v = 0) {
			n = i;
		} 
		else if (v = 1) {
			m = i;
		} 
		else {
			k = i;
		}
		v = v + 1;
	}
	int u, y, w, uym;
	v = 0;
	for (int i; n; 0) {
		cin >> uym;
		for (int b; uym ; 0) {
			if (v = 0) {
				u = b;
			} else if (v = 1) {
				y = b;
			} else {
				w = b;
			}
			v = v + 1;
		}
	}
	cout << u + y + w + m / k;
	return 0;
}

