#include<bits/stdc++.h>
using namespace std;
bool x(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c=0,r=0,rr=0,nm=0,a[101]={};
	cin>>c>>r;
	for(int i=1;i<=c*r;i++){
		cin>>a[i];
	}
	rr=a[1];
	sort(&a[1],a+c*r+1,x);
	for(int i=1;i<=c*r;i++){
		if(a[i]==rr){
			nm=i;
			break;
		}
	}
	if(nm<=c){
		cout<<"1 "<<nm;
		return 0;
	}
	int x=0,y=0;
	while(1){
		if(nm/c>0){
			nm-=c;
			x++;
		}else{
			break;
		}
	}
	if(x%2==0){
		if(nm==0){
		cout<<x<<" 1";
		return 0;
    	}
		y=r-nm+1;
	}else{
		if(nm==0){
		cout<<x<<" "<<r;
		return 0;
    	}
		y=nm;
	}
	cout<<x+1<<" "<<y;
	return 0;
}

