#include<bits/stdc++.h> 
using namespace std;
string s;
long long int i,k,maxn,a[15],n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		a[s[i]-'0']++;
	}
	for(i=10;i>=0;)
	{
		if(a[i]!=0)
		{
			a[i]--;
			cout<<i;
		}
		else
		i--;
	}
	return 0;
}
