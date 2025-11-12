#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int as(int n,int m){
	for(int i=n;i<m;i++){
		for(int j=i+1;j<m;j++){
			if(a[i]<a[j]&&a[i]>a[j+1]){
				
			}
		}
	}
}
int main(){
	//freopen(' .in','r',stdin);
	//freopen(' .out','w',stdout);
	int n,m,s,ans=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int q=a[0];
	for(int i=0;i<n*m;i++){
		if(a[i]==q){
			s=i;	
		}else{
		}
	}
	cout<<s/m+1<<" ";
	if((s/m+1)%2==0){
		cout<<5-s%m;
	}else{
		cout<<s%m+1;
	}
	return 0;
}
 
