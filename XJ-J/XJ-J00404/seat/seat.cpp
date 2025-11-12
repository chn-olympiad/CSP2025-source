#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,b,c,d,e;
	cin>>n>>m;
	c=n*m;
	int a[c];
	for(int i=0;i<c;i++){
		cin>>a[i];
	}
	s=a[0];
	sort(a,a+c);
	for(int i=0;i<c;i++){
		if(s==a[i]){
		    b=i+1;
		   	break;
	    }
	}
	d=c/b;
	e=c%b;
	cout<<d<<' ';
	if(d%2==0){
		cout<<m-e;
	}else{
		cout<<e+1;
	}
	return 0;
}
