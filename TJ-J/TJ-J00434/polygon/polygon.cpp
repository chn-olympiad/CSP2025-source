#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag = true;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i]>1){
			flag = false;
		}
	}
	sort(a+1,a+n+1);
	if(n==3){
		int k = a[3];
		int p = a[1];
		int q = a[2];
		int l = p+q;
		if(l<=k){
			cout<<0; 
		}else{
			cout<<1;
		}
	}else if(flag){
		cout<<0;
	}else{
		return 0;
	}
	cout<<"\n";
	return 0;
}
