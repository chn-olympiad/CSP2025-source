#include<bits/stdc++.h>
using namespace std;
double l()
{
	int a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	return sqrt(pow((a1-a2),2)+pow((b1-b2),2));
}
double d()
{
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	return abs(x*a+y*b+c)/sqrt(pow(a,2)+pow(b,2));
}
int main()
{
	int n;
	cin>>n;
	if(n==1)	
		cout<<l();
	if(n==2)
		cout<<d();
	return 0;
}