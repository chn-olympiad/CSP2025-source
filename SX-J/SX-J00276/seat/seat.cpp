#include<bits/stdc++.h>
using namespace std;
int main()
{
 	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m,x1,x2,x3,x4;
	cin>>n>>m>>x1>>x2>>x3>>x4;
			if(x1>x2>x3>x4)
			{
				cout<<"1"<<" "<<"1";
			}
			if(x1>x2>x4>x3)
			{
				cout<<"1"<<" "<<"1";
			}
			if(x1>x3>x2>x4)
			{
				cout<<"1"<<" "<<"1";
			}
			if(x1>x3>x4>x2)
			{
				cout<<"1"<<" "<<"1";
			}
			if(x1>x4>x3>x2)
			{
				cout<<"1"<<" "<<"1";
			}
			if(x1>x4>x2>x3)
			{
				cout<<"1"<<" "<<"1";
			}
			if(x2>x1>x3>x4)
			{
				cout<<"1"<<" "<<"2";
			}
			if(x2>x1>x4>x3)
			{
				cout<<"1"<<" "<<"2";
			}
			if(x4>x1>x2>x3)
			{
				cout<<"1"<<" "<<"2";
			}
			if(x4>x1>x3>x2)
			{
				cout<<"1"<<" "<<"2";
			}
			if(x3>x1>x4>x2)
			{
				cout<<"1"<<" "<<"2";
			}
			if(x3>x1>x2>x4)
			{
				cout<<"1"<<" "<<"2";
			}
			if(x3>x2>x1>x4)
			{
				cout<<"2"<<" "<<"1";
			}
			if(x3>x4>x1>x2)
			{
				cout<<"2"<<" "<<"1";
			}
			if(x4>x2>x1>x3)
			{
				cout<<"2"<<" "<<"1";
			}
			if(x4>x3>x1>x2)
			{
				cout<<"2"<<" "<<"1";
			}
			if(x2>x3>x1>x4)
			{
				cout<<"2"<<" "<<"1";
			}
			if(x2>x4>x1>x3)
			{
				cout<<"2"<<" "<<"1";
			}
			if(x2>x3>x4>x1)
			{
				cout<<"2"<<" "<<"2";
			}
			if(x2>x4>x3>x1)
			{
				cout<<"2"<<" "<<"2";
			}
			if(x3>x2>x4>x1)
			{
				cout<<"2"<<" "<<"2";
			}
			if(x3>x4>x2>x1)
			{
				cout<<"2"<<" "<<"2";
			}
			if(x4>x3>x2>x1)
			{
				cout<<"2"<<" "<<"2";
			}
			if(x4>x2>x3>x1)
			{
				cout<<"2"<<" "<<"2";
			}
	fclose(stdin);
	fclose(stdin);
 return 0;
}