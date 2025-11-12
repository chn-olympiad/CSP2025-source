#include<bits/stdc++.h>
using namespace std;
int a[1000],b[100][100],a1[100];
int main()
{
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
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(i % 2 == 1)               //奇数行：从上往下
			{
				b[j][i] = a1[num];
				num++;
				if(a1[num] == r)
				{
					cout << i << " " << j;
					break;
				}
			}
			else if(i % 2 == 0)          //偶数行：从下往上
			{
				b[i * j - num + 1][i] = a1[num]; 
				num++;
				if(a1[num] == r)              //判断小r成绩 
				{
					cout << i * j - num + 1 << " " << i;
					break;
				}
			}
		}
	}
	
	
	
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cout << b[i][j] << " ";
		}
	}
	return 0;
}
