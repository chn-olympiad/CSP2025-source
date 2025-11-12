#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
//I ac T2
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int arr[1001],cnt=0,n,m,id;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>arr[i];
	}
	
	cnt=arr[0];
	sort(arr,arr+n*m,cmp);
	/*for(int i=0;i<n*m;i++){
		cout<<arr[i]<<' ';
	}*/
	for(int i=0;i<n*m;i++){
		if(cnt==arr[i]){
			id=i+1;
			break;
		}
	}
	//cout<<id;
	cnt=1;
	while(id>n*2){
		id-=n*2;
		cnt+=2;
	}
	bool fl=0;
	if(id>n){
		cnt++;
		id-=n;
		fl=1;
	}
	if(!fl){
		cout<<cnt<<' '<<id;
	}
	else{
		cout<<cnt<<' '<<m-id+1;
	}
	return 0;
} 

//#Shang4Shan3Ruo6Shui4
