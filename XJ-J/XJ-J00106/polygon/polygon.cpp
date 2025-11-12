#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,c;
	scanf ("%d%d%d%d",&n,&a,&b,&c);
	int ma = max(a,b);
	ma = max(ma,c);
	ma = ma * 2;
	int add = a + b + c;
	if (add >= ma){
		printf ("1");
	}
	else {
		printf ("0");
	}
	return 0;
}
