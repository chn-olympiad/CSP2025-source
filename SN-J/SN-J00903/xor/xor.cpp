#include<bits/stdc++.h>
using namespace std;
int main()
{
	forpen("xor.in","r","stdin");
	forpen("xor.out","w","stdout");
	int n;
	int s;
	int c=0;
	cin>>n>>s;
	int a[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=s;i++)
	{
			for(int i=0;i<a[n];i++)
		{
			if(a[n-s]>=c)
			c=a[n-s];
		}
	}
	
		cout<<c;
		return 0;
}
