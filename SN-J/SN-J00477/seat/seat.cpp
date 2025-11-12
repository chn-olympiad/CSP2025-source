#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int arr[10][10];
	int a,s;
	cin>>a>>s;
	for(int i=0;i<a;i++){
		cin>>arr[i][i]; 
	}
	 for(int j=0;j<s;j++){
	 	cin>>arr[j][j];
	 }
	
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
