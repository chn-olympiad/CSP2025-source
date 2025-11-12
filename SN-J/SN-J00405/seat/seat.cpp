#include <bits/stdc++.h> 
using namespace std;

int a[105];

int main()
{
	freopen("seat3.in","r",stdin);
	//freopen("seat1.out","w",stdout);
	int n,m,bigger=0,smaller=0,biggerx=1,biggery=1;
	char s;
	//string s="1,2,3,4,5";
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);	
	for(int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<endl;
	}
	


	

	return 0;	
} 
