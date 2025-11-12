#include <bits/stdc++.h>
using namespace std;
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b=0,s;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0){
			b=a[i];
		}
	}sort(a,a+n*m);
	
	
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			s=n*m-i;
			break;
		}
	}
	
	int c,d,xx=s/n;
	if(s%n>0){
		xx=s/n+1;
	}
	if(xx%2==0){
		c=(n+1-s%m);
		
	}else if(xx%2==1){
		c=s%n;
		
	}d=s/n;
	cout<<d+1<<" "<<c;
	return 0;
} 
