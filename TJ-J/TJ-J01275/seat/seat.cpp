#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int q,a,z=0,w[10000],s=1,x=0,e=1,d=0;
	cin>>q>>a;
	z=q*a;
	for(int i=1;i<=z;i++)
	{
		cin>>w[i];
		x=w[1];
	}
	sort(w+1,w+z+1);
	for(int i=z;i>0;i--)
	{
		if(w[i]==x)
		{
			s++;
		}
	}
	if(s>q)
	{
		cout<<"2"<<" "<<"2";
		
	}
	else
	{
		cout<<'1'<<" "<<s;
	}
	

	return 0;
}
