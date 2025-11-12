#include<bits/stdc++.h>
using namespace std;
int a,b,n=1;
int c[1000],m[10000];
int lie,hang;
int y;
int main() 
{
	freopen(" seat.in","r",stdin);
	freopen(" seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
	cin>>c[i];
	}
	y=c[1];
    sort(c+1,c+1+a*b);
    for(int i=a*b;i>=1;i--){
	m[n]=c[i];
	n++;
	}
	for(int i=1;i<=a;i++){
	     if(y==m[i]){
	     	cout<<1<<" "<<i;
	     	return 0;
		 }
	}
	for(int i=a*b-a;i<=a*b;i++){
	     if(y==m[i]){
	     if(i/a==a){
	     	cout<<a<<" "<<a;
		 }
		 }
	}
	return 0;
}
