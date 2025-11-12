#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int n,ans=0;
string s;
void dfs(int i,int c,long long m,long long cc){
	if(c==0){
		if(cc>m*2)ans++;
		return;
	}
	for(;i<=n-c;i++){
		dfs(i+1,c-1,max(m,a[i]),cc+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=3;i<=n;i++)dfs(0,i,0,0);
	cout<<ans;
}
