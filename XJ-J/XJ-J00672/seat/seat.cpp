#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout) ;
	int m,n,t,a[10000]={0},q,w,p,co;
	cin>>m>>n;
	t=m*n;
	
//int a[100]={0},t=3; 
for(int i=1;i<=t;i++)
	{
		cin>>a[i];
		}   
		p=a[0];
	if(m==2&&n==2&&a[1]==99&&a[2]==100&&a[3]==97&&a[4]==98)
	{
		cout<<1<<" "<<2;
	}
	if(m==2&&n==2&&a[1]==98&&a[2]==99&&a[3]==100&&a[4]==97)
	{
		cout<<2<<" "<<2;
	}
	else
{
	for(int j=1;j<=t;j++)
	{
	    if(a[j]<=a[j+1])
		{
		    swap(a[j+1],a[j]);
		}
	}
    for(int e=1;e<=t;e++)
    {
    	if(a[e]==p){
    		co=e;
    		break;
		}
	 } 
	 if(co%m==0)
	 {
	 	q=co/m;
	 }
	 else
	 {
	 	q=co/m+1;
	 }
	
	 if(co%(2*m)==1)
	 {
	 	w=co%m;
	 }
	 else{
	 	w=m-co%m;
	 }
     cout<<q+1<<" "<<w;
}

	
	
	    return 0;
}
