#include<bits/stdc++.h> 
using namespace std;
int a[10001];
int main()
{
	feropen("number.in","r",std);
	feropen("number.out","w",std);
	for(int i = 0;i <= 10000;i++)
	{
		cin >> a[i];
	}
//	for(int i = 0;i <= 10000;i++)
//	{
//		sort(a[i],a[i+2])
//	}
	cout << a[1];
	return 0;
}
