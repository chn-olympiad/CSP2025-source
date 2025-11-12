#include<iostream>
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n ,m ,r;
	cin >> n >> m;
	cin >> r; 
	for(int i = 2 ;i <= n*m;i++)
	{
		int num;
		cin >> num;
		a[num] ++;
	}
	a[r]++; 
	int p = 0;
	for(int i = 100 ;i > r;i--)
	p+=a[i];
	cout << p/m+1;
	cout << " ";
	if(((p/m+1)% 2) != 0)
	{
		cout << p%m+1;
	}
	else
	cout << m-(p%m+1) + 1; 
	return 0;
 } 
