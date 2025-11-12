#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int num=0;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&a[i]!=a[i-1]){
			flag=0;
		}
		if(a[i]==1){
			num++;
		}
	}
	if(flag&&k==a[1]){
		cout<<n;
		return 0;
	}else if(flag&&k!=0&&k!=a[1]){
		cout<<0;
		return 0;
	}else if(flag&&k==0){
		cout<<n-1;
	}
	if(n==1&&a[1]!=k){
		cout<<0;
		return 0;
	}else if(n==1&&a[1]==k){
		cout<<1;
		return 0;
	}
	if(n==2&&k==0){
		if(a[1]==a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(k==1){
		cout<<num;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
