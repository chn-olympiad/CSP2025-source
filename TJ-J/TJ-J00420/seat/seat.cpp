#include<bits/stdc++.h>
using namespace std;
int a[101];
long long n,m;
long long c=1,r=1;
long long x=1;
int d=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>a[i-1]){
			a[i]=d;
			a[i-1]=a[i];
			d=a[i-1];
		 if(a[x]<a[x+1]){
		 	x++;
		 }
		}
	}
	for(int i=1;i<=n*m;i++){
		
			if(x>n){
				
			 	r=x-n;
			 	x=r;
			 	c++;
			 continue;
			}
			 if(x<=n){
			 	c=1;
			 	r=x;
			 }
			
			
		
	}
	cout<<r<<" "<<c;
fclose(stdin);
	fclose(stdout);
	return 0;
}
