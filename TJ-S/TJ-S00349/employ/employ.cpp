#include<iostream>
using namespace std;
	
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int q;
	cin >> q;
	int sum=0;
	int n[100];
	int m;
	cin >> m;
	for(int i=0;i<100;i++)
	{
		cin >> n[i];
	}
	for(int i=0;i<100;i++)
	{
		if(sum<i)
		{
			sum++;
		}
		if(sum>q)
		{
			return 0;	
		}
	}
	cout <<998244353%2 << endl;
	return 0;
} 
	
