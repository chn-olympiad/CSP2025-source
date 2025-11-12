#include <bits/stdc++.h>
using namespace std;

long long a[10] = {505585650, 504898585, 504899072, 507809873, 510567434, 504748585, 504878585, 504892585, 504598585, 5182974424};
int i;

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> i;
	cout << a[i % 10];
	return 0;
}
