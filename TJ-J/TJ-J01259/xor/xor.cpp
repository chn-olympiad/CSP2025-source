#include<bits/stdc++.h>
using namespace std;
int n,k; 
int a[500001],s[500001];
int v(int l,int r){
	for(int i=1;i<=max(l,r);i++){
		//string s0=tostring
		//if()
	}
}
void sol(int l,int r,int ans){
	cout<<ans;
	return;
}
void ol(){
	a[0]=0;
	//ans=0;
	for(int i=1;i<=n;i++){
		s[i]=v(s[i-1],a[i]);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) ans++;
	}
	if(k==0) sol(n,k,ans);
	else{
		ol();
	}
	return 0;
} 
