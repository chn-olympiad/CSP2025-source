#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","t",stdin);
	freopen("club.out","w",stdout);
	int i,j=3,t,n,max,ai1,ai2,ai3;
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ai1>>ai2>>ai3;
	 } 
	 if(ai1>=ai2,ai1>=ai3)
		max=ai1; 
	if(ai2>=ai1,ai1>=ai3)
	{
		max=ai2; 
	}
	if(ai3>=ai1,ai1>=ai2)
	{
		max=ai3; 
	}
	cout<<max<<endl;
	return 0;
 } 
