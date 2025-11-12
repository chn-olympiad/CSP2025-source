#include<bits/stdc++.h>
using namespace std;
int a[10];
char c;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin>>c)
	{
		if(isdigit(c))a[c-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]--)cout<<i;
	}
	return 0;
}
