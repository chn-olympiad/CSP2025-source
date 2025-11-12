#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int n,m;
	cin>>n>>m;
	int ans[n*m];
	for(int i=0;i<n*m;i++){
		cin>>ans[i];
	}
	int R=ans[0];
	int arr;
	for(int i=0;i<n*m;i++){
		for(int j=0;j<n*m;j++){
			if(ans[i]>ans[j]){
				arr=ans[i];
				ans[i]=ans[j];
				ans[j]=arr;
			}
		}
	}
	int a;
	for(int i=0;i<n*m;i++){
		if(ans[i]==R){
			a=i+1;
		}
	}
	if(a%n!=0 && (a/n)%2==0){
		cout<<a/n+1<<' '<<a%n;
	}else if(a%n!=0 && (a/n)%2!=0){
		cout<<a/n+1<<' '<<n-(a%n)+1;
	}else if(a%n==0 && (a/n)%2==0){
		cout<<a/n<<' '<<1;
	}else if(a%n==0 && (a/n)%2!=0){
		cout<<a/n<<' '<<n;
	}
	return 0;
} 
