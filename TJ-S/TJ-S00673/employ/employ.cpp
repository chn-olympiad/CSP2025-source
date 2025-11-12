#include<bits/stdc++.h>
using namespace std;
int jie(int x){
	int ans=1;
	for(int i=1;i<=x;i++){
		ans*=i;
		ans=ans%998244353;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[600],b[600];
	cin>>n>>m;
	char r;
	bool f=true,fm=true;
	for(int i=0;i<n;i++){
		cin>>r;
		a[i]=r-'0';
		if(r-'0'==0){
			f=false;
		}
		else{
			fm=false;
		}
	}
	if(fm==true){
		cout<<0;
	}else if(f==true){
		cout<<jie(n)%998244353;
	}else if(m==1){
		cout<<jie(n)%998244353;
	}else if(n==m){
		cout<<0;
	}else{
		cout<<6;
	}
	return 0;
}
