#include<bits/stdc++.h>
using namespace std;
int a[30];
int n;
int ans=0;
void dfs(int d,int m,int s){
     if(d==n){
     	if(s>m*2){
     	   ans++;	
		}
		return;
	 }	
	 dfs(d+1,m,s);
	 dfs(d+1,max(m,a[d]),s+a[d]);
}
int main(){
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
}
