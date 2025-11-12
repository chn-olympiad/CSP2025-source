//SN-J00674 段宇晨 西安滨河学校 
#include <bits/stdc++.h>
int a[1000005],x;
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
    for(int i = 0;i < s.size();i++)
    {
    	if(s[i] >= '0' && s[i] <= '9')
    	{
    		a[x] += s[i] - 48;
    		x++;
		}
	}
	sort(a,a + x);
	for(int i = x - 1;i >= 0;i--)
	{
		cout << a[i];
	}
	return 0;
}
