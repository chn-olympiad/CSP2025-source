#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int u[n]={0};
	int maxp=0;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>u[i];
		if(u[i]>maxp){
			maxp=i;
		}
	}
	for(int i=0;i<n;i++){
		if(i==maxp){
			continue;
		}
		else{
			ans+=u[i];
		}
	}
	if(ans>=u[maxp]*2){
		cout<<u[maxp];
	}
	return 0;
} 
