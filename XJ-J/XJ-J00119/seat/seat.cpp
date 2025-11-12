#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<n*m;i++){
		cin>>arr[i];
		if(arr[i]>k){
			ans++;
		}
	}
	arr[0]=k;
	sort(arr,arr+100);	
	int c,r;//c为列，r为行 
	for(int i=0;i<=ans;i++){
		c=i/m+1;
		if(c%2==0){
			r=m-i%m;
		}else{
			r=i%m+1;
		}
	}cout<<c<<' '<<r;
	return 0;
}
