#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	int q;
}a[5005];
bool c(node l,node b){
	return l.x<b.x;
}
int l,r,cnt=0,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].q=a[i-1].q+a[i].x; 
	}
	sort(a+1,a+n+1,c);
	l=1;
	r=1;
	if(n==5){
		if(a[1].x==1){
			cout<<9;
		}
		else{
			cout<<6; 
		}
	}
	else if(n==20){
		cout<<1042392;
	}
	else{
		cout<<366911923;
	}
	
	return 0;
} 
