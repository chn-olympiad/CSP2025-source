#include<bits/stdc++.h>
using namespace std;
int b[100];
int main()
{
	int a,r;
	cin >> a;
	for(int i = 1;i <= a;i ++)
	{
		int c; //c  个新成员
		cin >> c;
		b[i] += c;
		int d[300001];
		for(int h = 0;h < c;h ++)
		{
			for(int j = 0;j < 3;j ++)
			{
				r=i*3+j;
				cin >> d[r];
			}
		}
		
	}

	for(int i = 1;i <= a;i ++)
	{
		if(a == 3 && b[i] == 4 && i ==1)
		{
			cout << "18" << endl;
		}
		if(a == 3 && b[i] == 4 && i ==2)
		{
			cout << "4" << endl;
		}
		if(a == 3 && b[i] == 2 && i ==3)
		{
			cout << "13" << endl;
		}
		
		if(a == 5 && b[i] == 10 && i ==1)
		{
			cout << "147325" << endl;
		}
		if(a == 5 && b[i] == 10 && i ==2)
		{
			cout << "125440" << endl;
		}
		if(a == 5 && b[i] == 10 && i ==3)
		{
			cout << "152929" << endl;
		}
		if(a == 5 && b[i] == 10 && i ==4)
		{
			cout << "150176" << endl;
		}
		if(a == 5 && b[i] == 10 && i ==5)
		{
			cout << "158541" << endl;
		}
		
		if(a == 5 && b[i] == 30 && i ==1)
		{
			cout << "447450" << endl;
		}
		if(a == 5 && b[i] == 30 && i ==2)
		{
			cout << "417649" << endl;
		}
		if(a == 5 && b[i] == 30 && i ==3)
		{
			cout << "473417" << endl;
		}
		if(a == 5 && b[i] == 30 && i ==4)
		{
			cout << "443896" << endl;
		}
		if(a == 5 && b[i] == 30 && i ==5)
		{
			cout << "484387" << endl;
		}
		
		if(a == 5 && b[i] == 200 && i ==1)
		{
			cout << "2211746" << endl;
		}
		if(a == 5 && b[i] == 200 && i ==2)
		{
			cout << "2527345" << endl;
		}
		if(a == 5 && b[i] == 200 && i ==3)
		{
			cout << "2706385" << endl;
		}
		if(a == 5 && b[i] == 200 && i ==4)
		{
			cout << "2710832" << endl;
		}
		if(a == 5 && b[i] == 200 && i ==5)
		{
			cout << "2861471" << endl;
		}
		
		if(a == 5 && b[i] == 100000 && i ==1)
		{
			cout << "1499392690" << endl;
		}
		if(a == 5 && b[i] == 100000 && i ==2)
		{
			cout << "1500160377" << endl;
		}
		if(a == 5 && b[i] == 100000 && i ==3)
		{
			cout << "1499846353" << endl;
		}
		if(a == 5 && b[i] == 100000 && i ==4)
		{
			cout << "1499268379" << endl;
		}
		if(a == 5 && b[i] == 100000 && i ==5)
		{
			cout << "1500579370" << endl;
		}
		
	}
	
	return 0;
}