#include<bits/stdc++.h>
using namespace std;
int a[5050];
int n;
int ans=0;
void f(int maxn,int s,int t){
	if(t==n){
		if(s>2*maxn){
			ans++;
			ans%=998244353;
		}
		return;
	}else{
		f(maxn,s,t+1);
		f(max(maxn,a[t]),s+a[t],t+1);
	}
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	f(0,0,0);
	cout<<ans;
	return 0;
}

