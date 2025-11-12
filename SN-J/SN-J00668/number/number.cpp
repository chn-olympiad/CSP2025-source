incloud <stdc++.h>
using namespace.std;
int main()
{
	freopen('number.in','r',stdin);
	freopen('number.out','w',stdout);
	long long s;
	int a;
	cin >> s;
	for (i=0,i<=s,i++)
	{
		if(s[i]<= s[i+1])
		{
			s[i+1] = s[i];
			s[i] = s[i+1];
			
		}
	}
	a = s[0];
	cin >> s[i];
	cout << s;
	cout << s[i];
	
	
	return 0;
}


