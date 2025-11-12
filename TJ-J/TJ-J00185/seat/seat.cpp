#include<iostream>
#include<cstring>
using namespace std;
char a[1000000],d[1000000];
int main(){
	int m,n;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		d[i]=a[i];
	}
	int s;
	for(int i=0;i<n*m;i++){
		if(a[i]<a[i+1]){
			s=a[i];
			a[i]=a[i+1];
			a[i+1]=s;
		}
		else if(a[i]>=a[i+1]){
			continue;
		}
	}
	int c=1,r=1,q=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==d[1]){
			q=i;
			if(q>n){
				while(q<=n){
					q=q-n;
					c++;
				}
			    if(q==0){
			    	r=m;
				}
				else if(c%2==0){
					r=n-q;
				}
			}
			else{
				r=q;
				c=c+1;
			}
		}
		else{
			continue;
		}
	}
	cout<<r<<" "<<c;
	return 0;
}
