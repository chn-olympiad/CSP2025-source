#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];}
	int t=a[1];
	if(n==1&&m==1) cout<<"1 1";
	else if(n==1){
		int u;
		sort(a+1,a+1+m);
		for(int j=m;j>=1;j--){
			if(t==a[j]){
				u=m-j+1;
				break;}}
		cout<<u<<" 1";}
	else if(m==1){
		int u;
		sort(a+1,a+1+n);
		for(int j=n;j>=1;j--){
			if(t==a[j]){
				u=n-j+1;
				break;}}
		cout<<"1 "<<u;}
	else if(n==2){
		int u;
		sort(a+1,a+1+2*m);
		for(int j=2*m;j>=1;j--){
			if(t==a[j]){
				u=2*m-j+1;
				break;}}
		if(u%4==1) cout<<(u+1)/2<<" 1";
		else if(u%4==2) cout<<u/2<<" 2";
		else if(u%4==3) cout<<(u+1)/2<<" 2";
		else cout<<u/2<<" 1";}
	else{
		int u;
		sort(a+1,a+1+n*m);
		for(int j=n*m;j>=1;j--){
			if(t==a[j]){
				u=n*m-j+1;
				break;}}
		if((u+n-1)/n%2==1&&u%n!=0) cout<<(u+n-1)/n<<" "<<u%n;
		else if((u+n-1)/n%2==1) cout<<(u+n-1)/n<<" "<<n;
		else if((u+n-1)/n%2==0&&u%n!=0) cout<<(u+n-1)/n<<" "<<u%n;
		else cout<<(u+n-1)/n<<" 1";}
	return 0;
}
