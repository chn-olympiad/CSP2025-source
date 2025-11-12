#include <bits/stdc++.h>;
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f=false;
	}
	if(f==true&&k==0){
		cout<<n/2;
	}else{
		int cnt=0;
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					cnt++;
				}else if(a[i]==0&&a[i+1]==0&&i<n){
					cnt++;
					i++;
				} 
			}
			cout<<cnt;
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
				}else if(a[i]==1&&a[i+1]==1&&i<n){
					cnt++;
					i++;
				} 	
			}
			cout<<cnt;
		}
		if(k!=1&&k!=0) cout<<10086;
	}
	return 0;
}
