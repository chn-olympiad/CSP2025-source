#include<bits/stdc++.h>
using namespace std;
int array[100];
int main(){
	int n,m,a,b;
	int hao;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>array[i];
	}
	b=array[0];
	for(int j=0;j<n*m;j++){
		for(int i=0;i<n*m;i++){
			if(array[i]<array[i+1]){
				a=array[i];
				array[i]=array[i+1];
				array[i+1]=a;
			}
		}
	}for(int i=0;i<m*n;i++){
		if(array[i]==b){
			hao=i+1;
			break;
		}
	}
	int c=0,r=1;
	for(c;c<=m;c){
		c++;
		if(hao==0){
			break;
		}
		for(r;r<=n;r++){
			hao--;
			if(hao==0){
				break;
			}
		}
		if(hao==0){
			break;
		}
		c++;
		r--;
		for(r;r>=1;r--){
			hao--;
			if(hao==0){
				break;
			}
		}
		if(hao==0){
			break;
		}
		r++;
	}
	cout<<c<<' '<<r;
	return 0;
}
