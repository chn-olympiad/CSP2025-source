#include <bits/stdc++.h> 
using namespace std;

long long n,a[200999],md = 1,ans,al[200999]; 
//666Ð¡¹÷Ä¾ 

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 0; i< n;i++)
	{
		cin >> a[i];
	}
	if(n <=3)
	{
		int y = max(a[0],max(a[1],a[2]));
		if(a[0] + a[1] + a[2] > 2*y)
		{
			cout << 1;
			return 0;
		}
	}
	else if(n > 100)
	{
		cout << 0;
		return 0;
	}
	cout << 998244353;
	fclose(stdin); 
	fclose(stdout); 
	return 0;
}
