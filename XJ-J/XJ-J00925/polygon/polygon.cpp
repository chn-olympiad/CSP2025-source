#include<bits/stdc++.h>
using namespace std;
int a[100005],flag=0; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=1;
		}
	}
	sort(a+1,a+n+1);
	if(n==1) cout<<0;
	else if(n==2) cout<<0;
	else if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else cout<<0;
	}
	else if(flag==0) {
		cout<<(n-2)*(n-2)+1;
	}
	return 0;
}
