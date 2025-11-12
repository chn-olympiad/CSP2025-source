#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	int n,m;
	bool f=true;
	cin>>n>>m;
	int a=n*m;
	int s[a+1],i,z,sum=0,t,e;
	for(i=1;i<=a;i++)
	{
		cin>>s[i];
	}
	t=s[1];
	while(f){
		sum=0;
		for(i=1;i<a;i++)
		{
			if(s[i]<s[i+1])
			{
				z=s[i];
				s[i]=s[i+1];
				s[i+1]=z;
			}
		}
		for(i=1;i<a;i++)
		{
			if(s[i]>s[i+1])
			{
				sum++;
			}
		}
		if(sum==a-1)
			f=false;
	}
	for(i=1;i<=a;i++)
		if(s[i]==t)
			e=i;
	int c,r;
	c=e/n;
	if(c==0)
		c=1;
	r=e%n;
	if(r!=0)
		c=c+1;
	if(c%2==1)
		{
			if(r==0){
				r=n;
			freopen("seat.out","w",stdout);
				cout<<c<<" "<<r<<endl;	
			}
			if(r!=0){
			freopen("seat.out","w",stdout);
				cout<<c<<" "<<r<<endl;	
			}
		}
	else if(c%2==0)
		{
			if(r==0){
				r=1;
			freopen("seat.out","w",stdout);
				cout<<c<<" "<<r<<endl;	
			}
			if(r!=0){
				r=n-r+1;
			freopen("seat.out","w",stdout);
				cout<<c<<" "<<r<<endl;
			}
		}

	return 0;
}
