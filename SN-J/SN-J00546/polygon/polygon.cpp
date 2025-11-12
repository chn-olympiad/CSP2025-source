#include<iostream>
using namespace std;
int n,b=0,c=0;
int a[5010]
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b+=a[i];
		if(i>=3&&b>2*a[i]){
			c+=1;
		}
	}
	cout<<c;
    return 0;
} 
