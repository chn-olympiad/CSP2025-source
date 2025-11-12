#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int m,n;
cin>>m>>n;
int arr[1000];
int b=m*n;
for(int i=0;i<b;i++){
	cin>>arr[i];
}
int a=arr[0];
for(int i=0;i<b;i++){
	for(int j=0;j<i;j++){
		if(arr[i]>arr[j]){
			swap(arr[i],arr[j]);
		}

	}

}
for(int i=0;i<b;i++){
	for(int j=0;j<i;j++){
		if(arr[i]==a||arr[j]==a){
		cout<<j+1<<" "<<i+1<<" ";
	        return 0;
		}

	}

}
fclose(stdin);
fclose(stdout);
return 0;
}
