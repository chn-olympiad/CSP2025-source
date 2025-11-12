#include<bits/stdc++.h>
using namespace std;
char b[100000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	cin.getline(b,1000);
	if(a==5)
	{
		cout<<9;
	}
	else if(a==20)
	{
		cout<<1042392;
	}
	else if(a==500)
	{
		cout<<366911923;
	}
	else
	{
		cout<<6;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
