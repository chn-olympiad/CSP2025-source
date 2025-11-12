#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, m;
	int c, r;
	int a[1000], b[1000], q = 1;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	for(int j = 1; j <= n * m; j++)
		if(a[1] < a[j])
			q = q + 1;
	if(q % n == 0)
		c = q / n;
	else
		c = q / n + 1;
	if(q % (2 * n) == 0 && (q / (2 * n)) % 2 == 0)
		r = 1;
	if(q % n == 0 && (q / n) % 2 != 0)
		r = n;
	if((q / n) % 2 != 0 && r != n)
		r = n - q % n + 1;	
	else
		r = q % (2 * n);
	cout << c << " "<< r;
	return 0;
} 
