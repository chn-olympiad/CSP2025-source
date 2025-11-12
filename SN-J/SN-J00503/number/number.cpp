#include<iostream>
using namespace std;
int main (){
	int a,i,j,d;
	cin>>a;
	i=10;
	j=100;
	if(a%i>=a%j){
	d=a%i;
	}else{
	d=a%j;	
	}
    cout<<d;
    return 0;
}
