#include <iostream>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n*m];
	int s=1;
	for(int i=0; i<n*m; i++){
		cin >> a[i];
		if(a[i] > a[0]) s++;
	}
	int N, M;
	if(s%n == 0) M=s/n;
	else M=s/n+1;
	if(M%2 == 0) N=n-s%n+1;
	else N=n-s%n;
	cout << M << ' ' << N;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
