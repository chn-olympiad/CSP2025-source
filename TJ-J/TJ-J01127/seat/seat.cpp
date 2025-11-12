#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,b,h;
	cin>>n>>m;
	h=n*m;
	int a[10000]={};
	for(int i=1;i<=h;i++){
		cin>>a[i];		
		if(i==1){
			b=a[i];
		}
	}
	sort(a+1,a+h+1);
	int c,r,cnt=0,id=1;
	for(int i=h;i>=1;i--){
		if(a[i]>b) cnt++;
		if(a[i]==b) break;
		id++;
	}
	if(id%n==1){
		c=id/n+1;
		if(c%2!=0)r=id%m;
		else r=id-id%m;
	}
	else{
		c=id-id/m;
		r=c/n+id;
	}
	cout<<c<<" "<<r;
//2 2
//98 99 100 97
//2 2
//99 100 97 98	
//3 3
//94 95 96 97 98 99 100 93 92
	
	
	return 0;
} 
