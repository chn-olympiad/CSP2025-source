#include <bits/stdc++.h>
using namespace std;
	int n, m , k;
int main()
{
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
	int wi, c, cj, aji;
	cin >> n >> m >> k >> wi >> cj >> aji;
	int cf = (n - 1) * m * k;
	int gf = c * cj;
	cout << cf + gf; 
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
