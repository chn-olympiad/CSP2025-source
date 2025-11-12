#include<bits/stdc++.h>
using namespace std;
long long arr[300010]={0};
int work(long long arr[],int n,int i,int count,int u,int a,int b,int c){
	if(i==n*3){
		if(a>u||b>u||c>u){
			return 0;
		}
		return count;
	} 
	if(a>u||b>u||c>u){
		return 0;
	}
	return max(max(work(arr,n,i+3,count+arr[i+1],u,a,b+1,c),work(arr,n,i+3,count+arr[i+2],u,a,b,c+1)),work(arr,n,i+3,count+arr[i],u,a+1,b,c));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int a=0,b=0,c=0,u=n/2;
		for(int j=0;j<n*3;j+=3){
			for(int x=0;x<3;x++){
				cin>>arr[j+x];
			}
		}
		cout<<work(arr,n,0,0,u,a,b,c)<<endl;
	}
	return 0;
}

