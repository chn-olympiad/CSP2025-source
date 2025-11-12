#include<bits/stdc++.h>
#define endl putchar('\n')
#define air putchar(' ')
using namespace std;
map<int,int>mp;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	int n=x.size();
	for(char i:x)
	{
		if(i<='9'&&i>='0') mp[i-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=mp[i];j++)
		{
			putchar(i+'0');
		}
	}
	return 0;
}
/*
      A           CCC
     A A         C
    A   A       C
   AAAAAAA     C
  A       A     C
 A         A     C
A           A     CCC
*/
