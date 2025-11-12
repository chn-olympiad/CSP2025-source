#include<bits/stdc++.h>
using namespace std;
int  k;
int a[10001];
bool vis[1001][1001];
long long int n,ans;
/*void dfs(int s,int xo){
	stack<int> q;
	if(xo==k)ans++;
	for(int i=n;i>s;i--){
		q.push(a[i]);
	}
	while(!q.empty()){
		int x=q.top();
		xo=xo xor x;
		//dfs(s,xo);
	}dfs(s+1,a[s+1]);
}*/
int main(){
freopen("xor","r",stdin);
freopen("xor","w",stdout);
	cin>>n>>k;	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}//dfs(1,a[1]);
	
    for(int i=1;i<=n;i++){
    	for(int j=1;i+j<=n;j++){
    		int w;
    		for(int k=i;k<=i+j;k++){
    			if(a[k]xor w==k&&vis[i][k]==0)ans++,vis[i][k]=1;
    			w^=a[k];
			}
		}
	}
    cout<<ans;
	return 0;/*
4 3
2 1 0 3*/
	//cout<<1;
}
