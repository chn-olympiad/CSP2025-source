#include <bits/stdc++.h> 
using namespace std;

long long num[2008686], q = 0; 
string a;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i = 0; i < a.size();i++)
	{
		if(a[i] - '0' < 10)
		{
			num[q] = a[i] - '0';
			q++;
		}
	}
	sort(num,num + q);
	for(int i = q-1;i>=0;i--)
	{
		cout << num[i];
		if(num[i] == 0 && i == q-1)
		{
			return 0;
		}
	}
	fclose(stdin); 
	fclose(stdout); 
	return 0;
	
}
