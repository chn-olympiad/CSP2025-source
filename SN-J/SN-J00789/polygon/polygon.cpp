#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	int n;
	cin>>n;
	int a[n];
	int num=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		num=num+a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]>a[i]){
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	int max=a[0]*2;
	int b[(n-3)*n]={max};
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int g=num;
			g=g-i;
			if(g>max){
				sum++;
			}
		}
		for(int j=n;j<2*n;j++){
			for(int l=j+1;l<2*n;l++){
				int g=num;
				g=g-i-j;
				if(g>max){
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
