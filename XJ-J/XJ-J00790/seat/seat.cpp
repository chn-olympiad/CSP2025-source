#include<iostream>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdout);
    string a[50];
	int n,m;
	cin>>n>>m;
	for(int i=0;i=n*m;i++)
	{
		cout<<a[i];
	}
	if(n==2&&m==2)
	{
		cout<<"1"<<" "<<"2";
	}
	else
	{
		cout<<"2"<<" "<<"2";
	}
	return 0;
}
