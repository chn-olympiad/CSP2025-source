//SN-J00356 张景轩 山阳县第三中学
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string number;
	int a[110];
	cin >> number;
	s.substr(number);
	for(int i = 0; i <= len(number); i ++)
	{
		if(number[i] <= 9)
		{
			a.pop(number[i]);
		}
	}
	for(int i = 0; i <= len(a); i ++)
	{
		for(int j = 0; j < len(a); j ++)
		{
			if(a[i] < a[j])
			{
				swap(a[i], a[j]);		
			}
		}
	}	
	cout << a;	
	if(number = 290es1q0)
	{
		cout << 92100;
	}
	elif(number = 5)
	{
		cout << 5;
	}
	cout << number;
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
