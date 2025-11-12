#include<bits/stdc++.h>
using namespace std;
long long s;
double a[10];
double b=0;
double c=0;
double num(){
	for(int i=1 ;i<=10;i++){
		if(a[i]<a[i+1]){
			a[i]=b;
			a[i+1]=a[i];
			b=a[i+1];
		return a[i+1];a[i];
	}else{
	  return a[i];a[i+1];
		}
	
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	double num(s);
	cout<<s;
	
	return 0;
}
