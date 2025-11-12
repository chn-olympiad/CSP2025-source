#include<iostream>
#include<string>
using namespace std;
int n,m;
int a[10005],b,c,k,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	c=n*m;
	k=a[0];
	for(int j=0;j<c;j++){
		for(int i=0;i<c;i++){
			if(a[j]>=a[i]) {
				b=a[j];
				a[j]=a[i];
				a[i]=b;
			}
		}
	}
	for(int i=0;i<c;i++){
		if (a[i]==k)
			b=i;
	}
	b+=1;
	if(b%m==0){
		x=b/m;
	}
	else{
		x=b/m+1;
	}
	if (x%2==0){
		if(b%m==0) y=1;
		else y=m+1-b%m;
	}
	else{
		if(b%m==0) y=m;
		else y=b%m;
	}
	cout<<x<<" "<<y;
	return 0;
} 
