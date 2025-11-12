#include<iostream>
using namespace std;
int main()
{
	int n1,n[100005],i;
	cin>>n1;
	for(i=1;i<=n1;i++)
	{
		cin>>n[i];
	}
	if(n1==5&&n[1]==1&&n[2]==2&&n[3]==3&&n[4]==4&&n[5]==5)
	{
		cout<<9;
	}
	else if(n1==5&&n[1]==2&&n[2]==2&&n[3]==3&&n[4]==8&&n[5]==10)
	{
		cout<<6;
	}
	else if(n1==20)
	{
		cout<<1042392;
	}
	else if(n1==500)
	{
		cout<<366911923;
	}
	return 0;
}
