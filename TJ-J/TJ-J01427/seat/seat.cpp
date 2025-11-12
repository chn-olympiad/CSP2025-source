#include <iostream>
using namespace std;
long long a1,n,m,x,num,lie,hang;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a1;
	for (int i=2;i<=n*m;i++)
	{
		cin >> x;
		if (x>a1) num++;
	}
	num++;

	if (num%n!=0) lie=num/n+1;
	else lie=num/n;

    if (lie%2==0)
    {
    	if (num%n==0) hang=1;
    	else hang=n-num%n+1;
	}
	else
	{
		if (num%n==0) hang=n;
		else hang=num%n;
	}

    cout << lie << " " << hang;
	return 0;
}
