#include<bits/stdc++.h>
using namespace std;
int main()
{
	"freopen.in","r",stdin;
	"freopen.out","w",stdout;
	int s;
	cin>>s;
	int maxn=-2e9;
	int sum=0;
	for(int i=1;i<=s;i++)
	{
		int x;
		cin>>x;
		if(x>maxn)
		{
			maxn=x;
	    }
	}
	cout<<maxn;
}