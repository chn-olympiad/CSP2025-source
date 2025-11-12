#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			int k=s[i]-'0';
			a[k]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]--)
		{
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}