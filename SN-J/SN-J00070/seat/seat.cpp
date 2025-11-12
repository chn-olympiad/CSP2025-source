#include<bits/stdc++.h>
using namespace std;
int a[5];
int b[5];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
    int a,b,c,d;
	cin>>a>>b>>c>>d;
    int a1=1,a2=2,b1=1,b2=2;
 
	    if(a>b&&a>c&&a>d){
		cout<<a1<<" "<<b1;}
		
		if((a<b&&a>c&&a>d)||(a<c&&a>b&&a>d)||(a<d&&a>b&&a>c)){
		cout<<a1<<" "<<b2;}
		
		if((a<b&&a<c&&a>d)&&(a<b&&a<d&&a>c)&&(a<c&&a<d&&a>b)){
		cout<<a2<<" "<<b2;}
		
		if(a<b&&a<c&&a<d){
		cout<<a2<<" "<<b1;}
	
	
	
	return 0;
}
