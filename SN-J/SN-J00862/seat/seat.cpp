#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,r;

/*int cmp(int &a,int &b)
{
	
	return a>b;
}*/

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int students[n*m+5];
	int a;
	for(int i=0;i<n*m;i++)
	{
		cin>>students[i];
		a=students[0];
	}
	sort(students,students+n*m+5);
	int l=n*m-1,x=0;
	for(;l>=0;l--)
	{
	
		if(students[l]==a) 
		{
			break;
		}
	}
	l=n-l;
	

	
	if(l%n!=0) c=l/n+1;
	else c=l/n;
	if(l%(2*n) <=n) r=l%(2*n);
	else 
	{
		if(l%n==0) r=1;
		else r=n+1-l%n;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
