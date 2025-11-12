#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
char arr1[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>arr1;
	int ii=0;
    for(int i=0;i<=1001;i++){
    	if(arr1[i]<'10'&&arr1[i]>'0'){
    		arr[ii]=arr1[i]-48;
    	
    	    ii++;
		}
		if(arr1[i]){
			
		}
		else{
			break;
		}
	}
	sort(arr,arr+ii);
	for(int i=ii-1;i>=0;i--){
	    cout<<arr[i];
	}
	return 0;
	
}  
