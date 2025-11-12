#include <bits/stdc++.h>
using namespace std;
int b[15];
int main()
{
	string s;
	freopen("number.in","r",stdin);
	cin>>s;
	freopen("number.out","w",stdout);	
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=b[i];j++)
		{
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}