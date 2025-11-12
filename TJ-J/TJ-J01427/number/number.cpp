#include <iostream>
using namespace std;
long long a[15],ans;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin >> s;
    int len=s.length();
    for (int i=0;i<len;i++)
    {
    	if ('0'<=s[i] && s[i]<='9') a[s[i]-'0']++;
	}
	for (int i=9;i>=0;i--)
	{
		for (int j=1;j<=a[i];j++)
		{
			ans=ans*10+i;
		}
	}
	cout << ans;
	return 0;
}
