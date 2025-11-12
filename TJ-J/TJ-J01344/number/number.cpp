#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin)
	freopen("number.out","w",stdout)
	int a,a1,a2,a3,c1,c2;
	cin >> a;
	a3 = a/100;
	a2 = a/10 - a3*10;
	a1 = a-a3*100-a2*10;
	if(a1>=a2 && a2>=a3)
		cout << a1*100 + a2*10 + a3;
	if(a1>=a3 && a3>=a2)
		cout << a1*100 + a3*10 + a2;
	if(a1>=a3 && a2>=a1)
		cout << a2*100 + a1*10 + a3;
	if(a3>=a1 && a2>=a3)
		cout << a2*100 + a3*10 + a1;
	if(a3>=a2 && a2>=a1)
		cout << a3*100 + a2*10 + a1;
	if(a3>=a1 && a1>=a2)
		cout << a3*100 + a1*10 + a2;
	return 0;
}

