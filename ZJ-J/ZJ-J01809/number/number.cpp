#include<bits/stdc++.h>
using namespace std;
string s;
int f[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='a')	continue ;
		f[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		if(f[i])
			for(int j=1;j<=f[i];j++)
				cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
