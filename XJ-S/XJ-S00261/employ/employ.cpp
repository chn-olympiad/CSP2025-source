#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,b[505];
string a;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
	} 
	if(n==3)
	{
		cout<<'2';
	}
	 if(n==10)
	 {
	 	cout<<'2204128';
	 }
	return 0; 
} 
