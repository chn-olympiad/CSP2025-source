#include<bits/stdc++.h>
using namespace std;
int arr[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b=0;
	int c=1;
	int r=0;
	int x=n;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
		b=arr[1];
	}
	sort(arr+1,arr+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(m%2==0){
			r++;
			if(arr[i]==b){
				cout<<(n*m-i+1)/m+1<<" "<<r;
				return 0;
			}
			
			if(r==n){
				i++;
				for(int j=1;j<=n;j++){
					if(arr[i]==b){
						cout<<(n*m-i+1)/m+1<<" "<<r;
						return 0;
					}
					i++;
					r--;
				}
			}
		}else{
			x--;
			if(arr[i]==b){
				cout<<(n*m-i+1)/m+1<<" "<<x;
				return 0;;
			}
			
			if(x==1){
				i++;
				for(int j=1;j<=n;j++){
					if(arr[i]==b){
						cout<<(n*m-i+1)/m+1<<" "<<x;
						return 0;;
					}
					i++;
					x++;
				}
			}
		}
	}
	return 0;
}
