#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[1005]; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
	}
	int cnt=arr[1],sum=0;
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(cnt==arr[i])sum=i;
	}
	int k=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			k++;
			if(k==sum){
				k-=(i-1)*n;
				if(i%2==1){
					cout<<i<<" "<<k;
				}else{
					cout<<i<<" "<<n-k+1;
				}
				break;	
			}
		}
	}
	return 0;
} 
