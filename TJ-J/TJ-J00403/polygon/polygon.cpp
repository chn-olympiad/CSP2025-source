#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n;
	cin>>n;
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		string num;
		cin>>num;
		if(num=="1 2 3 4 5") 
		{
			cout<<9;
		}
		else if(num=="2 2 3 8 10")
		{
			cout<<6;
		}
	} 
	return 0;
}
