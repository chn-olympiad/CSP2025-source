#include <bits/stdc++.h>
using namespace std;

string a;

int num[11];

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	
	cin >> a;
	
	int n = a.size();
	
	for(int i = 0;i < n;i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			int k = a[i] - '0';
			num[k]++;
		}
	}
	
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 1;j <= num[i];j++)
		{
			cout << i;
		}
	}
	
	return 0;
}
