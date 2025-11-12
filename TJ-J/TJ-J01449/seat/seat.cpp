#include<bits/stdc++.h>
using namespace std;
long long brr[12345][12345],arr[12345];
bool cmp (long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long m,n;
	cin>>m>>n;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	long long xr=arr[1],js=1;
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				brr[i][j]=arr[js];
				js++;
			}
		}else{
			for(int j=1;j<=n;j++){
				brr[i][j]=arr[js];
				js++;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(brr[i][j]==xr){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
} 
