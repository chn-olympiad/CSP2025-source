#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a=0;
	int arr[1005];

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		
		cin>>arr[i];
		
	}
	int e=arr[1];
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(arr[i]==e){
		    a=i;	
		}
	}
	int c=0;
	if(a%m==0){
		cout<<a/m<<" ";
		c=a/m;
	}
	else{
		cout<<a/m+1<<" ";
		c=a/m+1;
	}
	if(a/m==0){
		cout<<a;
	}
	else if(c%2==0||a%m==1){
		cout<<m;
	}
	else if(c%2==0){
		cout<<n-a%m;
	}
	else if(a%m==0){
		cout<<m;
	}
	else{
		cout<<a%m;
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
