#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],sum,s,ansx,ansy;
int cmp(int x,int y){
	return x>y;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			s=i;
			break;
		}
	}
	if(s%m!=0){
		ansx=s/m+1;
	}else{
		ansx=s/m;
	}
	if(ansx%2==1){
		if(s%n==0){
			ansy=n;
			
		}else{
			ansy=s%n;
		}
	}else{
		if(s%n==0){
			ansy=1;
		}else{
			ansy=n;
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
