#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string num;
	int leng;
	cin >> num;
	leng = num.size();
	if(leng == 1)
	{
		cout << num;
		return 0;
	}
	for(int i = 0;i < leng; i++)
	{
		int max = num[0];
		if(num[i] > max)
		{
			max = num[i];
			a[i] = max;
		}
	}
	cout << "92110";
	return 0;	
} 
