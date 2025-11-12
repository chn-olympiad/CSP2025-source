#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m, n , sn;
	cin >> m >> n;
	cin >> sn;
	int num = 1;
	for(int i = 2 ; i<= m * n ; i++)
	{
		int x;
		cin >> x;
		if(x > sn)
			num ++;		
	}
//	cout << num << endl;
	int sh ,sl , np;
	np = n * 2;
	sh = num % np;
	if(sh > n)
		sh = np - sh + 1;
	
	if(num % n == 0)
	{
		sl = num / n;
	}
	else
	{
		sl = num / n ;
		sl ++;
	}
	
	cout << sl  << " " << sh;
	
	
	return 0;
}
