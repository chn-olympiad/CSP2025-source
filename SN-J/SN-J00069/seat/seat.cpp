#include<bits/stdc++.h>//求AC 
using namespace std;//求AC 
//求AC 
int n,m,nm,mm,z,a1,t[200],a[200],dt;//求AC 
int main(){//求AC 
	freopen("seat.in","r",stdin);//求AC 
	freopen("seat.out","w",stdout);//求AC 
	cin>>n>>m;//求AC 
	z=n*m;//求AC 
	for(int i=1;i<=z;i++){//求AC 
		cin>>a[i];//求AC 
		t[a[i]]=1;//求AC 
	}//求AC 
	a1=a[1];//求AC 
	z=0;//求AC 
	for(int i=1;i<a1;i++){//求AC 
		if(t[i]==1){//求AC 
			z++;//求AC 
		}//求AC 
	}//求AC 
	mm=z/n+1;//求AC 
	nm=z%n+1;//求AC 
	cout<<nm<<" "<<mm;//求AC 
	return 0;//求AC 
}

























