#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	int n=x*y,a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int m=a[1],s,p;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(a[i]==m)
		{
			m=n-i+1;
			break;
		}
	if(m<y)
		cout<<1<<" "<<m<<endl;
	else 
	{	
		s=m/y;
		p=m%y;
		cout<<s<<endl;
		cout<<p<<endl;
		if(p==0)
		{
			if(s%2==0)
			{
				cout<<s<<" "<<1<<endl;
			}
			else
			{
				cout<<s<<" "<<y<<endl;
			}
		}
		else
		{
			if(s%2==0)
			{
				cout<<s+1<<" "<<p<<endl;
			}
			else
			{
				cout<<s+1<<" "<<y-p+1<<endl;
			}
		}
	}

	return 0;
}
