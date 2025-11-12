#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N =12;
int main ()
{
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	int set [N][N];
	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			cin >> set[i][j];
			
	if(n%2==1)
		cout << n << ' ' << m;
	else {
		cout << n << ' ' << "1";
}
	return 0;
}
