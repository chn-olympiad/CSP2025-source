#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000],x,r1,r2,a1,sun,sum=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >>n>>m;
    x=n*m;
    for(int i=1;i<=x;i++)
    {
        cin>>a[i];
        a1=a[1];
    }
    sort(a+1,a+x+1);
    for(int i=1;i<=x;i++)
    {
    	if(a1>=a[i])
    	{
    		sum++;
		}
    }
    sun=sum-1;
    r1=sum;
    r2=sun;
    if(r1/m==1&&r1%m==0)
    {
    	cout<<n;
	}
	if(r1%m==1)
	{
		r1=r1/m;
		cout<<" "<<n-r1;
	}
	if(r2%m==0||r2==1)
	{
		cout<<" "<<m;
	}
	else
	{
		cout<<" "<<m-r2;
	}
    return 0;
}
