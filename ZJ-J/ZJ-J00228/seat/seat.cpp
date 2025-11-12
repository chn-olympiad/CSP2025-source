#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,a1,s=0,t,n1,m1;
	cin>>n>>m;
	cin>>a1;
	for(i=1;i<m*n;i++)
	{
		cin>>t;
		if(t>a1) s++;
	}
	n1=1;m1=1;
	if(s/n%2==0)
	{
		m1+=s/n;
		s=s%n;
		n1=s+1;
	}
	else
	{
		m1+=s/n;
		s=s%n;
		n1=n-s;
	}
	cout<<m1<<" "<<n1<<endl;
}
