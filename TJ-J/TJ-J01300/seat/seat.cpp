#include<bits/stdc++.h>
using namespace std;
int arr[105]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.out","w",stdout);	
	freopen("seat.in","r",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	int x=arr[1];
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(arr[i]==x){
			cout<<i/n+(i%n==0?0:1)<<" "<<((i/n+(i%n==0?0:1))%2==0?(m-(i%m==0?m:i%m)+1):(i%m==0?m:i%m));
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
