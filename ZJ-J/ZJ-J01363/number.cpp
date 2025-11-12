#include <bits/stdc++.h>
using namespace std;
string s,sum;
long long ans=0,a[10];
bool mycmp(long long a,long long b)
{
	if(a<b)
		return false;
	return true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		for(int j=0;j<=9;j++)
			if((s[i]-'0') == j)
				a[j]++;	
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			cout<<i;
			a[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}