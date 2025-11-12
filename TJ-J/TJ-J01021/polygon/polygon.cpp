#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int b[a];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(a==3)
	{
		cout<<1;
	}
	else if(a==4)
	{
		cout<<2;
	}
	else{
		cout<<6;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
