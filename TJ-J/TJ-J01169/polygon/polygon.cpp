#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int b[5005];
const int mod=998244353;

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	
	if(b[3]>2*a[3]){//¹«Ê½
		cout<<1<<endl;
		return 0;
	}
	
	cout<<0<<endl;
	return 0;
	
} 
