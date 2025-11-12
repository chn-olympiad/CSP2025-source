#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

//放个注释证明这是我自己写的  >:) 

long long num[11];

int digit(char x)
{
	if (0 <= (x - '0'))
	{
		if ((x - '0') <= 9)
		{
			return int(x - '0');
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	char x[1000010];
	int Size = 0;
	
	for (int i = 0; i <= 1000010; i++)
	{
		x[i] = getchar();
		if (x[i] == '\n')
		{
			break;
		}
		//cout << Size << endl;
		Size++;
	}
	
	//int sf = 0;
	
	for (int i = 0; i < Size; i++)
	{
		//cout << digit(x[i]) << endl;
		//cout << x[i] << endl;
		
		if (digit(x[i]) >= 0)
		{
			num[digit(x[i])]++;
		}
		//else
		//{
		//	sf++;
		//}
	}
	
	//cout << sf;
	
	for (int i = 9; i >= 0; i--)
	{
		for (long long j = 0; j < num[i]; j++)
		{
			cout << i;
		} 
	}
	//cout << endl;
	//for (int i = 9; i >= 0; i--)
	//{
	//	cout << num[i] << endl;
	//}
	//cout << Size;
	
	return 0;
} 
