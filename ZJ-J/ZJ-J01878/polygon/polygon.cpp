#include<bits/stdc++.h>
using namespace std;
long long int k;
long long int a[100001];
long long int n,ans;
void dfs(int s,int xo,int c){
	stack<int> q;
	if(c==0)ans++,s++,dfs(s,a[s],k-a[s]);
	for(int i=n;i>=s;i--){
		q.push(a[i]);
	}
	while(!q.empty()){
		int x=q.top();
		xo^=x;
		dfs(s,xo,c-xo);
	}
}
int main(){
	//freopen("polygon","r",stdin);
	//freopen("polygon","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}dfs(1,a[1],k-a[1]);
	cout<<ans;
	return 0;
}/*
4 3
2 1 0 3*/
