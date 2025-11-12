#include<bits/stdc++.h>
using namespace std;
int m,n,s[105],a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	a=s[0];
	int q=0;
	for(int i=0;i<n*m;i++){
		if(s[i]>a)
		q++;
	}
	if(q<n)
	cout<<'1'<<" "<<q+1;
	if(q==n)
	cout<<'2'<<" "<<n;
	if(q>n){
		int b=q/n;
		int c=q%n;
		if(b%2==0&&c==0){
			cout<<b+1<<" "<<'1';
		}
		if(b%2!=0&&c==0){
			cout<<b+1<<n;
		}
		if(c!=0&&b%2==0){
			cout<<b+1<<" "<<c+1;  
		}
		if(c!=0&&b%2!=0){
			cout<<b+1<<" "<<m-c;
		}
	}
	
	return 0; 
}
