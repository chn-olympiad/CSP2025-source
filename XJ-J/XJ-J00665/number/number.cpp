#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	char s[10000];
	int t=0;
	for (int i = 0; i < strlen(s); i++)
	{
		cin >> s[i];
		for (int j = 1; j <= i;j++)
		{
			s[i]=int();
			if(s[i]>s[i+1])
			{
				t+=s[i];
			}
	    }
	    cout << t;
    }
	return 0;
}
