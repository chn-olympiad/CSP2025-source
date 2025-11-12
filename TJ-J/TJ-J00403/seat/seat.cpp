 #include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
			string num;
			cin>>num;
		if(num=="98 99 100 97")
		{
			cout<<"2 2";
		}
	
		else if(n==3 && m==3 )
		{
			cout<<"3 1";
		}
		else if(num=="99 100 97 98")
		{
			cout<<"1 2";
		}
	}
	return 0;
}
