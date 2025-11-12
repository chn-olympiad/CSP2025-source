#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q,sum=0;
	string s1,s2,t1,t2;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>s1>>s2;
	}
	for(int i=0;i<q;i++)
	{
		cin>>t1>>t2;
	}
	for(int i=0;i<n;i++)
	{
		if(s1 == t1 || s2 == t2)
			sum++;
	}
	cout<<sum;
}
