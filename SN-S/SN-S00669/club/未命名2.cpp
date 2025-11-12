#include<bits/stdc++.h>
using namespace std;
int dfs(int a){
	if(l1<=(n/2)&&l2<=(n/2)&&l2<=(n/2)){
		ans1 = max(d[a][1],max(d[a][2],d[a][3]));
		ans2 = max(d[a][2],d[a][3]);
		ans3 = min(d[a][1],min(d[a][2],c));
		dfs(a+1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					m[i] = 
				}
			}
		}
	}
}
