#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],mx;
void dfs(int x,int h,int an,int bn,int cn){
	if(x>n){
		mx=max(mx,h);
		return;
	}
	if(an!=n/2){
		dfs(x+1,h+a[x],an+1,bn,cn);
	}
	if(bn!=n/2){
		dfs(x+1,h+b[x],an,bn+1,cn);
	}
	if(cn!=n/2){
		dfs(x+1,h+c[x],an,bn,cn+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		mx=0;
		dfs(1,0,0,0,0);
		cout<<mx<<'\n';
	}
	return 0;
}

