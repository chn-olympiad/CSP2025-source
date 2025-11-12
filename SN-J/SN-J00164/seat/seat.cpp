#include<bits/stdc++.h>
using namespace std;
int a[1000],b[100][100],a1[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m , n;
	cin >> m >> n;   //n行m列 
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}                //输入顺序 

	int r = a[1],num=1; 
	sort(a,a + n * m + 1);  //排序 
	
	for(int i = 1;i <= m * n;i++)
	{
		a1[i] = a[m * n - i + 1];
	}                            //调整顺序：从大到小 
	
	b[1][1] = a1[1];
	b[2][1] = a1[2];
	b[2][2] = a1[3];
	b[1][2] = a1[4];
	for(int i = 1;i <= 2;i++)
	{
		for(int j = 1;j <= 2;j++)
		{
			if(b[i][j] == r)
			{
				cout << j << " " << i;
			}
		}
	}
	return 0;
}
