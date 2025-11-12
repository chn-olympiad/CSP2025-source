#include<iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int a[101]={};
	int r;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0){
			r=a[i];
		}
	}
	for(int i=0;i<n*m+1;i++){
		for(int k=0;k<n*m-1;k++){
			if(a[k]<a[k+1]){
				int t=a[k];
				a[k]=a[k+1];
				a[k+1]=t;
			}
		}
	}
	int x=0,y=1;
	for(int i=0;i<n*m;i++){
		if(y%2==1){
			if(x<n){
				x++;
			}
			else{
				y++;
			}
		}
		else if(y%2==0){
			if(x>1){
				x--;
			}
			else{
				y++;
			}
		}
		if(a[i]==r){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
	}
	return 0;
}

