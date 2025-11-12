#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[110]={};
bool downn(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a=n*m;
	for(int i=1;i<=a;i++){
		cin>>arr[i];
	}
	int r=arr[1];
	sort(arr+1,arr+a+1,downn);
	for(int i=1;i<=a;i++){
		if(r==arr[i]){
			r=i;
			break;
		}
	}
	int x=(r-1)/n+1;
	int y;
	if(x%2==1){
		if(r%n==0){
			y=n;
		}else{
			y=r%n;
		}
	}else{
		int j;
		if(r%n==0){
			j=n;
		}else{
			j=r%n;
		}
		y=n+1-j;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
