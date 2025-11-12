#include <bits/stdc++.h>
using namespace std;
int arr[105],n,m,x=0,y=0,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>arr[0];
	s=arr[0];
	for(int i=1;i<n*m;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n*m);
	for(int i=n*m-1;i>=0;i--){
		if(x%2==1){
			y++;
			if(y>n){
				x++;
				y=n;
			}
		}else{
			y--;
			if(y<1){
				x++;
				y=1;
			}
		}
		if(arr[i]==s){
			cout<<x<<" "<<y;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
