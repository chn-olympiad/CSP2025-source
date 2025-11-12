#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n*m]={0};
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	int r=arr[0];
	for(int i=0;i<n*m;i++){
		int max=i;
		for(int j=i+1;j<n*m;j++){
			if(arr[max]<arr[j]){
				max=j;
			}
		}
		if(arr[max]==r){
			cout<<i/m+1<<" ";
			if(i/m%2==0){
				cout<<i%m+1;
			}
			else{
				cout<<m-(i%m+1)+1;
			}
			fclose(stdin);
			fclose(stdout);	
		}
		swap(arr[max],arr[i]);
	}
	return 0;
}
