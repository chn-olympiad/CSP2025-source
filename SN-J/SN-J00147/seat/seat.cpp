//SN-J00147 刘逸扬 西安辅轮中学 
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){//降序 
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[100] = {};
	cin >> n >> m;
	for(int i = 0; i < n * m; i++)
	{
		cin >> a[i];
	}
	int ren = a[0];
	sort(a,a + n * m,cmp);
	for(int i = 0; i < n * m; i++)
	{
		if(a[i] == ren)
		{
			ren = i + 1;//由于i从0开始，需+1偏正 
			break;
		}
	}
	
	int lie = floor(ren / n);//满列数量 
	if(ren % n == 0){//整列 
		if(lie % 2 == 1)//满列为奇数
		{
			cout << lie << ' ' << n;
		}
		else
		{
			cout << lie << ' ' << 1;
		}
	}
	else
	{
		int hang;
		if(lie % 2 == 0)//满列为偶数，即未满列为奇数列 
		{
			hang = ren - lie * n;
		}
		else//未满列为偶数列 
		{
			hang = m - (ren - lie * n) + 1;
		}
		cout << lie + 1 << ' ' << hang;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
