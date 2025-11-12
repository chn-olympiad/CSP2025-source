#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int s;
    int a[1000000];
    for(int i = 1;i <= s ;i++)
    {
    	cin >> a[i];
    	if(a[i] == 1)
    	{
    		cout << a[i];
    		return 0;
		}
	}
	for(int i = 1;i <= s ;i++)
	{
		if(a[i] < a[i + 1])
		{
			a[i + 1];
		}
	}
	cout << a;
    return 0;
}

