#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
int c[505];
int flag=1;

long long mul(int x){
	if(x==1){
		return 1;
	}
	return x*mul(x-1)%998244353;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]==0) flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag==1){ //针对特殊性质A，所有人都可以通过，什么顺序都可以 
		long long sum=mul(n);
		cout<<sum;
	}
	return 0;
}
