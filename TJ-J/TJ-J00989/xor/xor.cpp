#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define int long long 
int n,k;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]==k){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(n==2){
		if(a[1]==k&&a[2]==k){
			cout<<2;
			return 0;
		}
		if(a[1]!=k&&a[2]!=k&&a[1]^a[2]!=k){
			cout<<0;
			return 0;
		}
		cout<<1;
		return 0;
	}
	bool flag=true;
	int n1=0,n2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			n1++;
		}else{
			n2++;
		}
		if(a[i]!=0&&a[i]!=1){
			flag=false;
		}
	}
	if(flag){
		if(k==0){
			cout<<n1+n2/2;
			return 0;
		}else{
			cout<<n2;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
