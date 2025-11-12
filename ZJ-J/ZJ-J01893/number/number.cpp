#include<bits/stdc++.h>
using namespace std;
string t;
long long a[35],s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=0;i<t.size();i++)
	{
		if(t[i]>=48&&t[i]<=57)
		{
			a[int(t[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]) 
		{
			cout<<i;
			a[i]--;
		}
	}	
	return 0;
}