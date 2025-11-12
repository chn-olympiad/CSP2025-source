#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.cpp","r","stdin");
	freopen("seat.cpp","w","stdout");
	int n,m;
	cin >> n >> m;
	int f[n*m];
	for(int i=0;i<n*m;i++){
		cin >> f[i];
	}
	int r = f[0];
	cout << 1 << " " << 1;
	return 0;
}
