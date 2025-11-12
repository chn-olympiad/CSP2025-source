#include<bits/stdc++.h>
using namespace std;
int n,ans;
int x[505]={0};
void dfs(int c,int y,int z,int m){
	for(int i=1;i<z;i++){
		if((y+x[i])<c*2)dfs(c,y+x[i],i,m+1);
	}
	if(m>=3)ans++;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n);
	for(int i=3;i<=n;i++){
		dfs(x[i],x[i],i,1);
	}
	cout<<ans*3<<endl;
}
