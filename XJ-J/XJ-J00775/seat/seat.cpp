#include<bits/stdc++.h>
using namespace std;
int main(){
	int mun[101][101];
	int a[101];
	int r,c,x,n=1;
	cin>>c>>r;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=r*c;i++){
		cin>>a[i];
		n++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int m=0;
			if(a[j]<a[j+1]){
				m=a[j];
				a[j]=a[j+1];
				a[j+1]=m;
			}
		}
	}
	n=1;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			mun[j][i]=a[n];
			n++;
		} 
		i++;
		for(int j=c;j>=1;j--){
			mun[j][i+1]=a[n];
			n++;
		} 
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(mun[j][i]==x){
				cout<<i<<" "<<j;
			}
		}  
		
	}
	/*cout<<endl;cout<<mun[j][i]<<" ";*/
	/*3 3
       94 95 96 97 98 99 100 93 92*/
}
