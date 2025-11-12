#include<iostream>
using namespace std;
int main {
	int n,number,a[1000000],i=0,b[10000],k=0,min=100000,o=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<=i;j++){
		if(a[j]==1||a[j]==2||a[j]==3||a[j]==4||a[j]==5||a[j]==6||a[j]==7||a[j]==8||a[j]==9){
			b[k]==a[j];
			k++;
		}	
	}
	for(int r=0;r<=k;r++){
	    for(int y=0;y<=k;y++){
		    if(b[y]<max){
			   min=b[y];
			   pop.b[y];
		    }
		    number=number+min*o;
     	}
    }
    cout<<number<<endl;
	return 0;
	
}
