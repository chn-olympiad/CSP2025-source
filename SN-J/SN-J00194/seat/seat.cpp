#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num[100001],n1,m1,ans;
	cin >> n >> m;
	int nm = m*m;
	for(int i=0;i<nm;i++)
	{
		cin >> num[i];
	}
	int rnum = num[0];
	for(int i=0;i<nm;i++)
	{
		int q;
		if(num[i] < num[i+1])
		{
			q = num[i];
			num[i] = num[i+1];
			num[i+1] = q;
		}
	}
	int j;
	for(int i=0;i<nm;i++)
	{
		if(rnum == num[i])
		{
			j = i+1;
			break;
		}
	}
	
	m1 = j/n;
	if(m1*n < j) m1++;
	ans = j%n;
	
	if(ans == 1) n1 = n;
	else if(m1 % 2 == 0) n1 =  ans;
	else if(m1 %2 != 0) n1 = n - ans;
	cout << m1 << " " << n1;
}
