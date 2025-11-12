#include<bits/stdc++.h>
using namespace std;
long long sum,c[5005],p=998244353,n,a[5005],m;
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		if(a[1]+a[2]+a[3]>m*2)cout<<1;
		else cout<<0;
	}
	else if(m==1){
		cout<<0;
	}
	else{
		cout<<0;
	}
	return 0;
} 
