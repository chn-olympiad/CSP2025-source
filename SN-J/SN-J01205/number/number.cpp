#include <iostream>

using namespace std;
int m[10000] = {0};
int sd[10000] = {0};
string n;
string as;
int main()
{
	
//	freopen("numdrer","r",stdin);
//	freopen("numdrer","w",stdans);
    char a;
    int c;
    cin >> n;
    for(int i = 1;i <= size(n);i++)
	{
		a = n[i - 1];
		a -= '0';
		if(a >= 1 && a <= 9)
		{
			c += 1;
			a = m[c - 1];
		}
	}
	c = 0;
	for(int i = 1;i <= size(m);i++)
	{
		for(int j = 1;j <= size(m);j++)
		{
			if(m[j] > m[i])
			{
				c = m[j];
				m[j] = m[i];
				m[i] = c;
				c = 0;
			}
		}
	}
	for(int i = 1;i <= size(m);i++){
		sd = m[i - 1] + '0'
		a = sd[0];
		a += sd[i - 1];
	}
	a - sd[0] - '0';
	cout << a;
    return 0;
}

