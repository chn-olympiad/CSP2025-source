#include<bits/stdc++.h>
using namespace std;
string s;
int a[10]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			a[s[i]-'0']++;
	}
	for(int i = 9; i >= 0; i--)
	{
		if(a[i] != 0)
		{
			for(int k = 1; k <= a[i]; k++)
				cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
