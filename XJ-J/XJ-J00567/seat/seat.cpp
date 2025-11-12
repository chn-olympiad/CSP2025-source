#include<bits/stdc++.h>
using namespace std;

int main(){
	
	//freopen("seat.in",'r',stdin);
	//freopen("seat.out",'w',stdout);
	
	int n,m;
	cin>>n>>m;
	
	int a[m][n];
	
	for(int i=0;i<m;i++){
		if(i%2!=0){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		else{
			for(int j<n;j=0;j--){
				cin>>a[i][j];
			}
		}
	}
	int a1=a[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==a1){
				cout<<a[i][j];
			}
		}
	}
	
	//fclose(in);
	//fclose(out);
	
	return 0;
}
