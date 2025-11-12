#include<bits/stdc++.h>
using namespace std;
int arr[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,n,m;
	cin>>n>>m;
	for(int i=0;i<=n*m;i++){
		
		cin>>arr[i];
		if(arr[1]>arr[i]){
			cout<<"1 1";
		}else if(arr[1]<arr[i]){
			cout<<n<<m<<" ";
		}
	}



return 0;


} 
