#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1000005;
const ll M=1005;
string a;
int num[N];
int main()
{
	
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>a;
	ll j=1;
	for(ll i=0;i<a.length();i++)
	{
		if(int(a[i])-48<=9&&int(a[i])-48>=0)
			num[int(a[i])-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=num[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
} 

