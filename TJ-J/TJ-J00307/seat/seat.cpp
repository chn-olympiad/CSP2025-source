#include<bits/stdc++.h>
using namespace std;
int arr[105]={};
int brr[15][15]={};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i]; 
	}
	long long za=arr[1],s=0;
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			s++;
			if(i%2!=0){
				if(arr[s]==za){
					cout<<i<<" "<<j;
					return 0;
				}
			}else{
				if(arr[s]==za){
					cout<<i<<" "<<n-j+1;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
