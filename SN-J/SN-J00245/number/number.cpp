#include <bits/stdc++.h>
using namespace std;
int s[1000005] = {};
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string a;
    cin >> a;
    int cnt = a.length();
    int j = 0; 
    for(int i = 0; i < cnt; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            j++;
            s[j] = int(a[i] - 48);
        }
    }
	sort(s+1, s+j+1);
	for(int i = j; i >= 0; i--)
	{
		cout << s[i];
	}
    return 0;
}

