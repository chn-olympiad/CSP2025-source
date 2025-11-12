#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r","stdin");
	//freopen("xor.out","w","stdout");
	int n, k;
	cin >> n >> k;
	if(n < 0 || k < 0)
	{
		return 0; 
	}
	else
	{
		cout << n * k * k / 2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
