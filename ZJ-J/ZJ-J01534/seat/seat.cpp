#include<bits/stdc++.h>
using namespace std;
int n,m,ls[1000001];
int main()
{ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int num = 1;//R是第几个座位 
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> ls[i];
		if(i != 1)
		{
			if(ls[i] > ls[1])
			{
				num++;
			}
		}
	}
	int lie;
	if(num % n == 0)
	{
		lie = num/n;//第几列 
	}
	else
	{
		lie = (num+n)/n;//第几列 
	}
	int hang;
	if(lie % 2 == 1)//奇数列 从上往下 
	{
		hang = num % n;
		if(hang == 0)
		{
			hang = n;
		}
	}
	else//偶数列 从下往上 
	{
		hang = n-(num % n)+1;
		if(hang == n + 1)
		{
			hang = 1;
		}
	}
	printf("%d %d",lie,hang);
	return 0;
}
