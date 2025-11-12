#include <iostream>
using namespace std;
int n,m,R,q,num,c,r;
int checkl(int x);
int checkh(int x);
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> R;
	num = n*m;
	for(int i = 2; i <= num; i++)
	{
		int x;
		cin >> x;
		if(x > R) q++;
	}
	q++;
	c = checkl(q);
	r = checkh(q);
	cout << c << " " << r << endl;
	
	
	return 0;
}
int checkl(int x)
{
	if(q%n == 0) return q/n;
	else
		return q/n+1;
}
int checkh(int x)
{
	if(m%2==1)
	{
		return x%n;
		if(r==0) return n;
	}
	else
	{
		return n-(x%n)+1;
	    if(r==n+1) return 1;
	}
}
//#Shang4Shan3Ruo6Shui4
//seat
/*
2 2
99 100 97 98
3 3
94 95 96 97 98 99 100 93 92

*/
