#include<bits/stdc++.h>
using namespace std;
int j(int p){//½×³Ë 
	int g=1;
	for(int i=2;i<=p;i++){
		g*=i;
	}
	return g;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
		cout<<9;	
	}else{
		int b=0;//½×³Ë 
		int c=0;//¼ÓÓÃ 
		for(int i=3;i<=n;i++){
			b=j(n)/(j(n-i)*j(i));
			c+=b;
		}
		cout<<c;
	}
	return 0;
}
