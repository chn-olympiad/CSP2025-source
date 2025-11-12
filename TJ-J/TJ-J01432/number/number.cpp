#include<iostream>
#include<algorithm>
#include<cstring> 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in.txt","r",stdin);
	freopen("number.out.txt","w",stdout);
	string s;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	long long int n=s.size();
	long long int z[n+5],x=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			z[x]=s[i]-48;
			x++;
		}
	}
	sort(z,z+x);
	for(int i=x-1;i>=0;i--)
	{
		cout<<z[i];
	}
	return 0;
}
