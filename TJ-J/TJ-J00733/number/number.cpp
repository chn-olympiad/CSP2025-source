include <bits/stdc++.h>
using namespace std;
int s[1000005];
int main()
{
	cin>>s;
	int b=s[0];
	int i=1;
	while (s)
	{
		if (s[i]>=b)
		{
			b+=s[i]*10;
		}
		else
		{
			b=b*10+s[i];
		}
		i++;
	}
	cout<<b;
	return 0;
}
