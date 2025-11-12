#include<bits/stdc++.h> 
using namespace std;
int a[100000];
int main(){
	long long n,m,x,z;
	cin>>n>>m;
	cin>>x;
	for(int y=1;y<n*m;y++){
		cin>>a[y];
	}
	for(int i=1;i<n*m;i++){
		for(int j=i;j>1;j--){
			if(a[j]>a[j-1]){
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
			}
		}
	}
	a[n*m+1]=x;
	for(int i=n*m;i>=2;i--){
		if(a[i]>a[i-1]){
			int t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
		}else{
			
			z=i/m;
			if(i%m==0){
				cout<<z<<" ";
			}else{
				cout<<z+1<<" ";
			}
			if(z%2==0){
				i++;
				if(i%m==0){
					cout<<"1";
				}else{
					cout<<m+1-i%m;
				}
			}else{
				i++;
				if(i%m==0){
					cout<<m;
				}else{
					cout<<i%m;
				}
			}
			return 0;
		}
	}
	cout<<"1 1";
	return 0;
}
