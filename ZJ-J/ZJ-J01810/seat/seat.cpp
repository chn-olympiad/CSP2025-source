#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105]={0};
int cnt=0,ans=0;
int l;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) ans++;
	}
	cnt=ans/n+1;
	l=ans%n;
	cout<<ans<<" "<<l<<endl;
	if(cnt%2!=0){
		cout<<cnt<<" "<<l+1;
	}else{
		cout<<cnt<<" "<<n-l;
	}
	return 0;
} 
