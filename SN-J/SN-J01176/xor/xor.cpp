#include<bits/stdc++.h>
using namespace std;
int ans;

int n,k;
int a[1000005];
int gf(int l,int r){
	int la=l-r+1;
	int c=0;
	for(int i=l;i<=r;i++){
		
		c^=a[i];
//		cout<<a[i];
	}
	return c;

}


void dfs(int l,int r){
//	cout<<l<<" "<<r<<endl;
	for(int i=l;i<=r;i++){
		
		
		int m=gf(l,i);
//		cout<<m;
		int n=gf(i+1,r);
//		cout<<n;
		if(m==k) ans++;
		
		if(n==k) ans++;
		
		
		if(l==r){
			break;
		} 

		dfs(l,i);
		dfs(i+1,r);
		
	}
}



int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,n);
	
	cout<<ans;
	

	
	return 0;
}
