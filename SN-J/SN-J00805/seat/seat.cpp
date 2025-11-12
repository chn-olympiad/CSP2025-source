#include<bits/stdc++.h>
using namespace std;
int n,m,a[205],b,d,c,r;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++)
    {
    	cin>>a[i];
    	b=a[1];
	}
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++)
	{
		if(b==a[i])
		d=i;
	} 
    if(d%n!=0&&d%n!=1) {
    	c=d/n+1;
    	if(c%2!=0)
    	{
    		r=d/n;
		}
		else{
			r=m-d%n+1;
		}
	}
    else {
    	c=d/n;
    	if(c%2!=0)
    	{
    		r=m;
		}
		else{
			r=1;
		}
	}
	 if(d%n!=0&&d%n==1) {
    	c=d/n+1;
    	if(c%2!=0)
    	{
    		r=1;
		}
		else{
			r=m;
		}
	}
    cout<<c<<" "<<r;
	return 0;
}
