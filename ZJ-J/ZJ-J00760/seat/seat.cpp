#include<bits/stdc++.h>
using namespace std;
int n, m, a[110], x, pos;
bool cmp(int x, int y){
	return x > y;
}
int main(){
	freopen("seat.in", "w", stdin);
	freopen("seat.out", "r", stdout);
	cin >> n >> m;
	int num = n * m;
	for(int i = 1; i <= num; i++){
		cin >> a[i];
	}
	x = a[1];
	sort(a + 1, a + num + 1, cmp);
	for(int i = 1; i <= num; i++){
		if(a[i] == x){
			pos = i;
			break;
		}
	}
	int lie = pos / n + 1, hang = 0;
	if(pos % n == 0) lie--;
	if(lie % 2 == 0){
		hang = n - (pos - pos / n * n) + 1;
	}
	else{
		hang = (pos - 1) % n + 1;
	}
	cout << lie << " " << hang;
	return 0;
}
