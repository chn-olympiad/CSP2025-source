#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=3){
		if(a[1]+a[2]>a[3]) cnt++;
		if(a[1]+a[3]>a[2]) cnt++;
		if(a[3]+a[2]>a[1]) cnt++;
	}
	cout<<cnt;
}