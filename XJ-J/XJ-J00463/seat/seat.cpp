#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
 int n,m,c,h,l,a,i,a1,a2;
 char k(1000) ;
i=m*n;
cin>>n>>m;
c=0;
cin>>a>>k;
if(a<k) c++;
if(i/2==0) l=c/(m+1)+1; h=m-(c%m)+1;
if(i/2!=0) l=c/(m+1)+1;
h=(c%n)+1;


cout<<h<<" "<<l;

return 0;}
   


	
	
