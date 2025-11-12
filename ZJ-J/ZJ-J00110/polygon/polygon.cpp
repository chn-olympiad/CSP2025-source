#include<bits/stdc++.h>
using namespace std;
int n,a[505],c=0,v[505],s=0,t=0;
bool check(int u){
	return t>c*2;
}
void dfs(int u,int k,int p){
	if(u==p+1){
		if(check(u))
			s=(s+1)%998244353;
		return;
	}
	
	for(int i=k+1;i<=n;i++)
		if(v[i]==0){
			c=a[i];
			t+=a[i];
			v[i]=1;
			dfs(u+1,i,p);
			v[i]=0;	
			t-=a[i];
		}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		memset(v,0,sizeof(v));
		dfs(1,0,i);
	}
		
	cout<<s;
	return 0;
}